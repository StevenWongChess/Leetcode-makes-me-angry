class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> dict;
        for(auto i: s){
            ++dict[i];
        }
        
        vector<pair<char, int>> v(dict.begin(), dict.end());
        sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second;  
        });
        
        int n = s.size();
        string ans(n, ' ');
        int it = 0;
        for(auto [x, y]: v){
            for(int i = 0; i < y; ++i){
                ans[it] = x;
                ++it;
            }
        }
        
        return ans;
    }
};