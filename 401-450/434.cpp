class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 1; i < n; ++i){
            if(s[i] == ' ' && s[i - 1] != ' '){
                ++ans;
            }
        }
        if(n != 0 && s[n - 1] != ' '){
            ++ans;
        }
        
        return ans;
    }
};