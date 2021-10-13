class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while(x){
            if(reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
                return 0;
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }
        return reverse;
    }
};