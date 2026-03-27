class Solution {
public:
    long long getCost(vector<int>& nums, vector<int>& cost, long long target) {
        long long total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += (long long)abs(nums[i] - target) * cost[i];
        }
        return total;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long start = 1;
        long long end = 1e6; 
        long long ans = 0;
        
        while (start < end) {
            long long mid = start + (end - start) / 2;
            long long cost1 = getCost(nums, cost, mid);
            long long cost2 = getCost(nums, cost, mid + 1);
            if (cost1 > cost2) {
                start = mid + 1;
                ans = cost2; 
            } 

            else {
                end = mid;
                ans = cost1;
            }
        } 
        return ans; 
    }
};