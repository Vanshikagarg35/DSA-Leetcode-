class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddcount = 0;
        int i = 0;
        int count = 0;
        int j = 0;
        int prefixeven = 0; // 1. Variable declare kiya
        
        while(j < nums.size()){
            
            // Right pointer 'j' sirf Odds par dhyan dega
            if(nums[j] % 2 != 0){
                oddcount++;
            }
            
            // Agar limit cross ho jaye, toh Extra Odd nikalo aur purane Evens bhool jao
            if(oddcount > k){
                prefixeven = 0; // Nayi window shuru hui hai
                
                while(oddcount > k){
                    if(nums[i] % 2 == 0){
                        i++;
                    }
                    else if(nums[i] % 2 != 0){
                        oddcount--;
                        i++;
                    }
                }
            }
            
            // Jab valid window ho, toh Left wale Evens gin kar window tight karo
            if(oddcount == k){
                while(nums[i] % 2 == 0){
                    prefixeven++;
                    i++;
                }
                
                count += 1 + prefixeven; // 2. Yahan typo theek kiya
            }
            
            j++;
        }
        return count;
    }
};