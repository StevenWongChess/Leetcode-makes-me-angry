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
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        else{
            if( x % 10 == 0){
                return x == 0;
            }
            int rev = 0;
            while(x > rev){
                rev *= 10; 
                rev += x % 10;
                x /= 10;
            }
            return x == rev || x == rev / 10;
        }
    }
};