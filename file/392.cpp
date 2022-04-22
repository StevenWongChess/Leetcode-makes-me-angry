class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(); int n = t.length();
        int i = 0; int j = 0;
        while(i < m){
            if(j == n)
                return false;
            if(s[i] == t[j]){
                i++; j++;
            }
            else{
                j++;
            }
        }
        return true;
    }
};