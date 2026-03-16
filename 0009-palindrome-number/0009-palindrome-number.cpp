class Solution {
public:
    bool isPalindrome(int x) {
        int temp =x;
        long long rev_num = 0;
        while(temp>0){
            int n = temp%10;
            rev_num = (rev_num*10) + n;
            temp=temp/10;
        }
        return (rev_num == x);
    }
};