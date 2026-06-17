class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else if (c == '#') {
                result += result; 
            } 
            else if (c == '%') {
                reverse(result.begin(), result.end());
            } 
            else {
                result.push_back(c);
            }
        }
        
        return result;
    }
};