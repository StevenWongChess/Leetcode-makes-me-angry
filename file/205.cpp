class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> dict;
        unordered_map<char, char> dict2;
        for(int i = 0; i < n; i++){
            if(dict.find(s[i]) == dict.end()){
                dict[s[i]] = t[i];
            }
            else{
                if(dict[s[i]] != t[i])
                    return false;
            }
            if(dict2.find(t[i]) == dict2.end()){
                dict2[t[i]] = s[i];
            }
            else{
                if(dict2[t[i]] != s[i])
                    return false;
            }
            
        }
        return true;
    }
};