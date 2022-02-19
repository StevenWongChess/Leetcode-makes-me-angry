class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount + 1);
        count[0] = 0;
        for(int i = 1; i <= amount; i++){
            int least = INT_MAX;
            for(auto j: coins){
                if(i - j >= 0 && count[i - j] != INT_MAX)
                    least = min(least, 1 + count[i - j]);
            }
            count[i] = least;
        }
        return count[amount] == INT_MAX ? -1 : count[amount];
    }
};