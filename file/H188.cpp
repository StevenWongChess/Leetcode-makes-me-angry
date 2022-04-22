class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> yes(k + 1, INT_MIN);
        vector<int> no(k + 1, 0);
        for(auto p: prices){
            for(int i = 1; i <= k; i++){
                yes[i] = max(yes[i], no[i - 1] - p);
                no[i] = max(no[i], yes[i] + p);
            }
        }
        return max(yes[k], no[k]);
    }
};