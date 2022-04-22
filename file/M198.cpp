class Solution {
public:
    int rob(vector<int>& nums) {
        int yes = 0;
        int no = 0;
        for(auto i: nums){
            int tmp = no;
            no = max(no, yes);
            yes = max(yes, tmp + i);
        }
        return max(yes, no);
    }
};