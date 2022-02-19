class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        vector<int> ans(m+n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[m + n - 2 - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for(int i = 0; i < m + n - 1; i++){
            ans[i + 1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        int len = 0;
        for(int i = n + m - 1; i >= 0; i--){
            if(ans[i] != 0){
                len = i;
                break;
            }
        }
        string s(len + 1, ' ');
        for(int i = 0; i <= len; i++){
            s[i] = (char)(ans[len - i] + '0');
        }
        return s;
    }
};