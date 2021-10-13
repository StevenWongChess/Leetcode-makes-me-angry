class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> yes(k + 1, INT_MIN);
        vector<int> no(k + 1, 0);
        for(auto i: prices){
            for(int j = 1; j <= k; j++){
                yes[j] = max(yes[j], no[j - 1] - i);
                no[j] = max(no[j], yes[j] + i);
            }
        }
        return no[k];
    }
};