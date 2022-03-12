class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int yes = INT_MIN; 
        int no = 0;
        for(auto i:prices){
            no = max(yes + i, no);
            yes = max(yes, no - i - fee);
        }
        return no;
    }
};