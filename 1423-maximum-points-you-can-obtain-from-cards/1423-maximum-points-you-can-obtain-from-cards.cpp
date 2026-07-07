class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;
        int totalSum = 0;
        
        for (int num : cardPoints) {
            totalSum += num;
        }
        
        if (windowSize == 0) return totalSum;
        
        int currentWindowSum = 0;
        int minSubarraySum = INT_MAX;
        int i = 0;
        int j = 0;
        
        while (j < n) {
            currentWindowSum += cardPoints[j];
            
            if (j - i + 1 > windowSize) {
                currentWindowSum -= cardPoints[i];
                i++;
            }
            
            if (j - i + 1 == windowSize) {
                minSubarraySum = min(minSubarraySum, currentWindowSum);
            }
            
            j++;
        }
        
        return totalSum - minSubarraySum;
    }
};