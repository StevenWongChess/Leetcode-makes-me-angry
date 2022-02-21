class Solution {
public:
    // bool legal(char c){
    //     return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    // }
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n - 1;
        while(l < r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            if(!isalnum(s[r])){
                r--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++; r--;
        }
        return true;
    }
};