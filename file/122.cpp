class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int yes = INT_MIN;
        int no = 0;
        for(auto i: prices){
            
            no = max(no, yes + i);
            yes = max(no - i, yes);
        }
        return no;
    }
};