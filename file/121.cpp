class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int low = 100000;
        for(auto i: prices){
            low = min(low, i);
            profit = max(profit, i - low);
        }
        return profit;
    }
};