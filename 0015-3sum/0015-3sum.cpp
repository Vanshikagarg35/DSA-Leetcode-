class Solution {
public:
void twoSum(int i, int target, vector<int>&nums, vector<vector<int>>&result ){
    int j = nums.size()-1;
    while(i<j){
        if(nums[i]+nums[j]<target) i++;
        else if(nums[i]+nums[j]>target) j--;
        else{
            result.push_back({-target , nums[i], nums[j]});
            while(i<j && nums[i] == nums[i+1]) i++;
            while(i<j && nums[j]==nums[j-1]) j--;
            i++;
            j--;
        }
    }

}
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        for(int i=0; i<nums.size()-2; i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            twoSum(i+1, -nums[i], nums, result);
             
        }
        return result;
    }
};