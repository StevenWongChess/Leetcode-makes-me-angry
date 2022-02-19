class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int length = 1; 
        int start = 0;
        for(int i = 0; i < n; i++){
            int tmp = 0;
            for(int j = 1; i + j < n && i - j >= 0; j++){
                if(s[i + j] != s[i - j]){
                    break;
                }
                tmp ++;
            }
            if(length < 2 * tmp + 1){
                length = 2 * tmp + 1;
                start = i - tmp;
            }
            tmp = 0;
            for(int j = 0; i + 1 + j < n && i - j >= 0; j++){
                if(s[i + 1 + j] != s[i - j]){
                    break;
                }
                tmp ++;
            }
            if(length < 2 * tmp){
                length = 2 * tmp;
                start = i - tmp + 1;
            }
        }
        return s.substr(start, length);
    }
};