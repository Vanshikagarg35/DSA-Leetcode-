class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i])-1;
            if(nums[index]>0) nums[index]=-nums[index];
            else{
                return abs(nums[i]) ;
            }
        }
        return -1;
    }
};