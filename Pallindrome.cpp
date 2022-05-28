class Solution {
public:
    bool isPalindrome(int x) {
        int rem = 0;
        int long temp = 0;
        int tm = x;
        while (x > 0)
        {
            rem = x % 10;
            temp = (temp*10) + rem;
            x = x / 10;
        }
        if (temp == tm)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};