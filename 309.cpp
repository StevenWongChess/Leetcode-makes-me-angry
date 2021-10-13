class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        int own = INT_MIN;
        int not_own = 0;
        int just_sell = 0;
        for(int i = 0; i < n; i++){
            int tmp = just_sell;
            int flag = not_own;
            just_sell = own + prices[i];
            not_own = max(not_own, tmp);
            own = max(flag - prices[i], own);
        }
        return max(not_own, just_sell);
    }
};