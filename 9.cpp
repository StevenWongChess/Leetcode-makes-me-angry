class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int origin = x;
        int reverse = 0;
        while(origin && reverse < INT_MAX / 10){
            reverse *= 10;
            reverse += origin % 10;
            origin /= 10;
        }
        return x == reverse;
        // method 2
        // if(x < 0)
        //     return false;
        // string s = to_string(x);
        // for(int i = 0; i < s.length(); i++){
        //     if(s[i] != s[s.length() - 1 - i])
        //         return false;
        // }
        // return true;
    }
};