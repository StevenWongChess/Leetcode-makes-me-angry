class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 0;
        for(auto i: nums){
            if(i == 0)
                return 0;
            else if(i < 0)
                sign++;
        }
        return 1 - 2 * (sign % 2);
    }
};