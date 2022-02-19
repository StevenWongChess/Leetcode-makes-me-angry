class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> dict1;
        unordered_map <char, char> dict2;
        if(s.length() != t.length())
            return false;
        for(int i = 0; i < s.length(); i++){
            if(dict1.find(s[i]) != dict1.end()){
                if(dict1[s[i]] != t[i])
                    return false;
            }
            else{
                dict1[s[i]] = t[i];
            }
            if(dict2.find(t[i]) != dict2.end()){
                if(dict2[t[i]] != s[i])
                    return false;
            }
            else{
                dict2[t[i]] = s[i];
            }
        }
        return true;
    }
};