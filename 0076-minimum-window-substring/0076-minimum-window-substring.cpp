class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int required = mp.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (j < s.length()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    required--;
                }
            }

            while (required == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIdx = i;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {
                        required++;
                    }
                }
                i++;
            }
            j++;
        }

        if (minLen == INT_MAX) return "";
        return s.substr(startIdx, minLen);
    }
};