class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        int tn = s.size();
        reverse(t.begin(), t.end());
        s = ' ' + s + '#' + t;
        int n = s.size() - 1;
        vector<int> next(n + 1);
        for(int i = 2, j = 0; i <= n; ++i){
            while(j && s[i] != s[j + 1])
                j = next[j];
            if(s[i] == s[j + 1])
                ++j;
            next[i] = j;
        }
        return s.substr(tn + 2, tn - next[n]) + s.substr(1, tn);
    }
};