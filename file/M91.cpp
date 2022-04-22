class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0 || s[0] == '0')
            return 0;
        int a = 1;
        int b = 1;
        for(int i = 1; i < n; i++){
            int sum = 10 * (s[i - 1] - '0') + s[i] - '0';
            if(sum % 10 == 0){
                if(sum == 0 || sum > 20)
                    return 0;
                swap(a, b);
            }
            else if(sum > 26 || sum < 10){
                a = b;
            }
            else{
                a += b;
                swap(a, b);
            }
        }
        return b;
    }
};