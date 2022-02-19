class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for(auto i: magazine){
            if(dict.find(i) != dict.end()){
                dict[i]++;
            }
            else{
                dict[i] = 1;
            }
        }
        for(auto i: ransomNote){
            if(dict.find(i) != dict.end()){
                dict[i]--;
                if(dict[i] < 0)
                    return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
};