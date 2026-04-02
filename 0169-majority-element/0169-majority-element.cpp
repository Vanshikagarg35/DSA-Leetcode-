class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int maxCount = INT_MIN;
        int ans;
        for(auto &pair : mp){
            maxCount = max(maxCount , pair.second);
            if(maxCount == pair.second) ans = pair.first;


        }
        return ans;
    }
};