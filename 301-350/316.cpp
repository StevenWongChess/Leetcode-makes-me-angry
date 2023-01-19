class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26,0);
        
        for(char c: s){
            ++count[c - 'a'];
        }
        
        string ans;
        for(auto c: s){
            if(!visited[c - 'a']){
                while(!ans.empty() && ans.back() > c && count[ans.back() - 'a']){
                    visited[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                visited[c - 'a'] = true;
                ans += c;
            }
            --count[c - 'a'];
        }
        
        return ans;
    }
};