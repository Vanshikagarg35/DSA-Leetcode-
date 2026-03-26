class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>pair(spells.size());
        sort(potions.begin(),potions.end());
        int n = potions.size();
        for(int i =0 ;i<spells.size(); i++){
            int start = 0;
            int end = n-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if((long long)spells[i] * potions[mid] >= success) end = mid-1;
                else if((long long)spells[i]*potions[mid]<success) start = mid+1;
            }
            pair[i]=n-start;
        }
        return pair;
    }
};