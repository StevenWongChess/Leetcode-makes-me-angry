class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0)
            return true;
        int l = 0;
        int r = 0;
        while(r < t.length()){
            if(s[l] == t[r]){
                l++; r++;
                if(l >= s.length())
                    return true;
            }
            else{
                r++;
            }
        }
        return false;
    }
};