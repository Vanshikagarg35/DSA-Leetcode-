class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        int baskets = 0;
        int count=0;
        int maxC = 0;
        unordered_map<int,int>mp;
        while(j<fruits.size()){
            // Agar 2 baskets bhari hain aur ek naya fruit aaya hai
            if(baskets==2 && mp.find(fruits[j])==mp.end()){
                while(mp.size()!=1){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0) {
                        mp.erase(fruits[i]);
                        baskets--; // Aapka logic: Fruit khatam, basket khali hui
                    }
                    i++;
                    count--;
                }
                
                baskets++; // Naya fruit add ho raha hai, toh basket wapas bhari
                mp[fruits[j]]++;
                j++;
                count++;
                maxC = max(count , maxC);
                
            }
            else{
                if(mp.find(fruits[j])==mp.end()) baskets++;
                mp[fruits[j]]++;
                j++;
                count++;
                maxC = max(maxC , count);
            }
        }
        return maxC;
    }
};