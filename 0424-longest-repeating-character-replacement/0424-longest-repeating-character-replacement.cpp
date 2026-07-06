class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxf = 0;
        int i = 0;
        int maxC = 0;
        
        for (int j = 0; j < s.length(); j++) {
            count[s[j] - 'A']++;
            maxf = max(maxf, count[s[j] - 'A']);
            
            while ((j - i + 1) - maxf > k) {
                count[s[i] - 'A']--;
                i++;
            }
            
            maxC = max(maxC, j - i + 1);
        }
        
        return maxC;
    }
};