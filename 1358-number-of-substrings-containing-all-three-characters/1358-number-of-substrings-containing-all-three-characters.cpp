class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int countA = 0;
        int countB = 0;
        int countC = 0;
        int totalsubstr = 0;
        int n = s.length();

        while (j < n) {
            if (s[j] == 'a') countA++;
            else if (s[j] == 'b') countB++;
            else if (s[j] == 'c') countC++;

            while (countA > 0 && countB > 0 && countC > 0) {
                totalsubstr += (n - j);
                
                if (s[i] == 'a') countA--;
                else if (s[i] == 'b') countB--;
                else if (s[i] == 'c') countC--;
                
                i++;
            }
            j++;
        }
        return totalsubstr;
    }
};