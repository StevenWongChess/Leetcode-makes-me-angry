class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dict;
        for(auto i: s){
            if(dict.find(i) != dict.end()){
                dict[i]++;
            }
            else{
                dict[i] = 1;
            }
        }
        for(int i = 0; i < s.length(); i++){
            if(dict[s[i]] == 1)
                return i;
        }
        return -1;
    }
};