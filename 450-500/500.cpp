class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string dict = "12210111011122000010020202";
        
        for(auto &w: words){
            bool flag = true;
            int n = w.size();
            char sample = dict[tolower(w[0]) - 'a'];
            for(int i = 1; i < n; ++i){
                if(dict[tolower(w[i]) - 'a'] != sample){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(w);
            }            
        }
        
        return ans;
    }
};