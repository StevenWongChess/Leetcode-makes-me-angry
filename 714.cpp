class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int own = INT_MIN;
        int not_own = 0;
        for(int i = 0; i < n; i++){
            own = max(not_own - prices[i] - fee, own);
            not_own = max(not_own, own + prices[i]);
        }
        return not_own;
    }
};