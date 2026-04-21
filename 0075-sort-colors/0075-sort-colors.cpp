class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int , int> mp;
        int index = 0;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(int i=0; i<3; i++){
            while(mp[i]>0){
                nums[index]=i;
                index++;
                mp[i]--;
            }
        }
        

    }
};