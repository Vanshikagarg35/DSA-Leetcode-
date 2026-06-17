class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> len(n, 0);
        long long curr_len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                curr_len = max(0LL, curr_len - 1);
            } 
            else if (s[i] == '#') {
     
                curr_len *= 2;
            } 
            else if (s[i] == '%') {
            } 
            else {
                curr_len++;
            }
            len[i] = curr_len;
        }

        if (curr_len == 0 || k >= curr_len) {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--) {
      
            long long prev_len = (i > 0) ? len[i - 1] : 0;
            
            if (s[i] == '%') {
                
                k = prev_len - 1 - k;
            } 
            else if (s[i] == '#') {
               
                if (prev_len > 0) {
                    k = k % prev_len;
                }
            } 
            else if (s[i] == '*') {
             
            } 
            else {
               
                if (k == len[i] - 1) {
                    return s[i]; 
                }
            }
        }
        
        return '.'; 
    }
};