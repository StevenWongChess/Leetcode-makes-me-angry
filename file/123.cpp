class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int yes1 = INT_MIN;
        int yes2 = INT_MIN;
        int no1 = 0;
        int no2 = 0;
        for(auto i: prices){
            yes2 = max(yes2, no1 - i);
            no2 = max(no2, yes2 + i); 
            yes1 = max(yes1, -i);
            no1 = max(no1, yes1 + i);
        }
        return no2;
    }
};