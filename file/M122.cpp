class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int yes = INT_MIN;
        int no = 0;
        for(auto i: prices){
            yes = max(yes, no - i);
            no = max(no, yes + i);
        }
        return no;
    }
};