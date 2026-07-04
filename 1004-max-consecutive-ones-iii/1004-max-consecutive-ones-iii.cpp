class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n = nums.size();
        int count=0;
        int maxC=0;
        int flip = 0;
        while(j<n){
            if(nums[j]==1){
                count++;
                maxC = max(maxC , count);
                j++;
            }
            else if(nums[j]==0){
                if(flip<k){
                    count++;
                    j++;
                    flip++;
                    maxC = max(maxC , count);
                }
                else if(flip==k){
                    while(nums[i]!=0){
                        i++;
                        count--;
                    }
                    count--;
                    flip--;
                    i++;
                }
            }
        }
        return maxC;
    }
};