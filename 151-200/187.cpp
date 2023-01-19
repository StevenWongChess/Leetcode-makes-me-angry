class Solution {
public:
    unordered_map<char, int> dict{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.size();
        if(n < 10)
            return ans;
        int x = 0;
        for(int i = 0; i < 9; ++i){
            x <<= 2;
            x += dict[s[i]];
        }
        
        unordered_map<int, int> count;
        for(int i = 0; i <= n - 10; ++i){
            x = ((x << 2) | dict[s[i + 9]]) & (0b11111111111111111111);
            ++count[x];
            if(count[x] == 2){
                ans.push_back(s.substr(i, 10));
            }
        }
        
        return ans;
    }
};