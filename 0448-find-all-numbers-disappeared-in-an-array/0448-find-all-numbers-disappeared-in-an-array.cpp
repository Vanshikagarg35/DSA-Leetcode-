class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int i = 1, j = 0;
        int n = nums.size();
        
        while(i <= n && j < n){
            if(nums[j] == i){
                i++;
                j++;
            }
            else if(nums[j] < i){
                j++; 
            }
            else if(nums[j] > i){
                result.push_back(i);
                i++; 

            }
        }

        while(i <= n){
            result.push_back(i);
            i++;
        }
        
        return result;
    }
};