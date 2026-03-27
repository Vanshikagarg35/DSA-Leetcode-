class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = 0;
        for(int w : weights) {
            end += w;
        }
        int ans = end; 
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int daysNeeded = 1;
            int currentLoad = 0;
            
            for(int i = 0; i < weights.size(); i++) {
                if (currentLoad + weights[i] > mid) {
                    daysNeeded++;
                    currentLoad = weights[i]; 
                } 
                else {
                    currentLoad += weights[i];
                }
            }
            if (daysNeeded > days) {
                start = mid + 1;
            } 
        
            else {
                ans = mid;
                end = mid - 1; 
            }
        }
        
        return ans;
    }
};