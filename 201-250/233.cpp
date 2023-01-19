class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        
        for(long i = 1; n >= i; i *= 10){
            ans += (n / (i * 10)) * i;
            int remain = n % (i * 10);
            if(remain / i >= 2){
                ans += i;
            }
            else if(remain / i == 1){
                ans += remain - i + 1;  
            }   
        }
        
        return ans;
    }
};