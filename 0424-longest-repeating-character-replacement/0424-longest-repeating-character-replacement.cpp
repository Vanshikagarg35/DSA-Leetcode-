#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    // Ek generic function jo kisi bhi 'target' character ke liye longest substring nikalega
    int charResp(string &s, int k, char target){
        int i = 0;
        int j = 0;
        int Kcount = 0;
        int count = 0;
        int maxC = 0;
        
        while(j < s.length()){
        
            if(Kcount == k && s[j] != target){
                while(s[i] == target){
                    count--;
                    i++;
                }
                count--;
                Kcount--;
                i++;
            }
            else{
                if(s[j] != target && Kcount < k) Kcount++;
                count++;
                maxC = max(maxC, count);
                j++;
            }
        }
        return maxC;
    }

    int characterReplacement(string s, int k) {
        unordered_set<char> uniqueChars;
        for(int i = 0; i < s.length(); i++){
            uniqueChars.insert(s[i]);
        }
        
        int longestsubstr = 0;

        for(char target : uniqueChars){
            int currentMax = charResp(s, k, target);
            longestsubstr = max(longestsubstr, currentMax);
        }
        
        return longestsubstr;
    }
};