class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        string palin = to_string(y);
        reverse(palin.begin(),palin.end());
        return x==stoll(palin);

    }
};