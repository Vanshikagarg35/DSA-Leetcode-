class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = n + 1;
        }

        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val <= n) {
                int index = val - 1;
                if (nums[index] > 0) nums[index] = -nums[index];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};