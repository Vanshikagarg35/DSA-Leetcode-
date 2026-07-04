class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int freq=0;
        int maxfreq = 0;
        map<int,int>mp;
        int n = s.length();
        while(j<n && i<=j){
            if(mp[s[j]]==0){
                mp[s[j]]++;
                freq++;
                maxfreq = max(freq , maxfreq);
                j++;

            }
            else if(mp[s[j]]>=1){
                while(s[i]!=s[j]){
                    mp[s[i]]--;
                    i++;
                    freq--;

                }
                mp[s[i]]--;
                i++;
                freq--;
                
            }

        }
        return maxfreq;
    }
};