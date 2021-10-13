class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; i - j >= 0 && i + j < n; j++){
                if(s[i - j] == s[i + j])
                    count++;
                else
                    break;
            }
            for(int j = 0; i - j >= 0 && i + 1 + j < n; j++){
                if(s[i - j] == s[i + 1 + j])
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};