class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int count = 0;
        int m = g.size(), n = s.size();
        int j = 0;
        
        for(int i = 0; i < m && j < n; ++i){
            while(j < n && g[i] > s[j]){
                ++j;
            }
            if(j < n){
                ++j;
                ++count;
            }
        }
        
        return count;
    }
};