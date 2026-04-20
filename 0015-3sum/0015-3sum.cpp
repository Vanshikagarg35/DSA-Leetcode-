class Solution {
public:
    void twoSum(int i, int j, int target, vector<int>&nums, vector<vector<int>>&result){
        while(i<j){
            
            if(nums[i]+nums[j]>target){
                j--;

            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                result.push_back({-target,nums[i], nums[j]});
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            return {};
        }
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            twoSum(i+1, nums.size()-1, -nums[i] , nums , result);
        }
        return result;
    }
};