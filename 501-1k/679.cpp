class Solution {
public:
    
    bool dfs(vector<double> cards){
        int n = cards.size();
        bool ans = false;
        if(n == 1){
            return abs(cards[0] - 24) < 0.1;
        }
        else{
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(i == j){
                        continue;
                    }
                    vector<double> v;
                    for(int k = 0; k < n; ++k){
                        if(k != i && k != j){
                            v.push_back(cards[k]);
                        }
                    }
                    double a = cards[i], b = cards[j];
                    
                    v.push_back(a + b);
                    ans |= dfs(v);
                    v.pop_back();
                    v.push_back(a - b);
                    ans |= dfs(v);
                    v.pop_back();
                    v.push_back(a * b);
                    ans |= dfs(v);
                    v.pop_back();
                    v.push_back(a / b);
                    ans |= dfs(v);
                    v.pop_back(); 
                }
            }
        }
        return ans;
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double> c(cards.begin(), cards.end());
        return dfs(c);
    }
};