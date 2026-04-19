class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int i = 0;
        int num = 1;
        int ans = -1;
        
        while (count < k) {
            if (i < arr.size() && arr[i] == num) {
                i++;
            } else {
                ans = num;
                count++;
            }
            num++;
        }
        
        return ans;
    }
};