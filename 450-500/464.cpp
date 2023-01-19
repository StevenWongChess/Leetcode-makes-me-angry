class Solution {
public:
    unordered_map<int, bool> dict;
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int n = maxChoosableInteger, total = desiredTotal;
        if(n * (n + 1) / 2 < desiredTotal)
            return false;
        return dfs(0, 0, n, total);
    }
    
    bool dfs(int used, int sum, int n, int total){
        if(!dict.count(used)){
            bool ans = false;
            for(int i = 0; i < n; ++i){
                if(((used >> i) & 1) == 0){
                    if(i + 1 + sum >= total){
                        ans = true;
                        break;
                    }
                    if(!dfs(used | (1 << i), i + 1 + sum, n, total)){
                        ans = true;
                        break;
                    }
                }
            }
            dict[used] = ans;
        }
        
        return dict[used];
    }
};