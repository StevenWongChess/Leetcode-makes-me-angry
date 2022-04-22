class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int yes = INT_MIN;
        int no = 0;
        int just_no = 0;
        for(auto i: prices){
            yes = max(yes, no - i);
            no = max(no, just_no);
            just_no = max(just_no, yes + i);
        }
        return max(no, just_no);
    }
};