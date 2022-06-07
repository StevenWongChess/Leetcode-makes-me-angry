class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; i + j < n && i - j >= 0; j++){
                if(s[i + j] == s[i - j])
                    ans++;
                else
                    break;
            }
            for(int j = 0; i + j + 1 < n && i - j >= 0; j++){
                if(s[i + j + 1] == s[i - j])
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};