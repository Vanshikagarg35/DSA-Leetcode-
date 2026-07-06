class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0;
        int j=0;
        int count=0;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            
            while(i < j && sum > goal){
                sum-=nums[i];
                i++;
            }
            
            if(sum==goal){
                count++;
                int temp_i = i;
                while(temp_i < j && nums[temp_i] == 0){
                    count++;
                    temp_i++;
                }
            }
            j++;
        }
        return count;
    }
};