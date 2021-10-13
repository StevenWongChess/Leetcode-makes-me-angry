class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0;
        int not_rob = 0;
        for(auto i: nums){
            auto tmp = rob;
            rob = not_rob + i;
            not_rob = max(tmp, not_rob);
        }
        return max(not_rob, rob);
    }
};