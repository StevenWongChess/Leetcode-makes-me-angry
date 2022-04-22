class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for(auto i: ransomNote){
            dict[i]--;
        }
        for(auto i: magazine){
            dict[i]++;    
        }
        for(auto [x, y]: dict){
            if(y < 0)
                return false;
        }
        return true;
    }
};