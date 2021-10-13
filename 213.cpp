class Solution {
public:
    int easy_rob(vector<int>& nums, int l, int r){
        int rob = 0;
        int not_rob = 0;
        for(int i = l; i <= r; i++){
            int tmp = rob;
            rob = not_rob + nums[i];
            not_rob = max(tmp, not_rob);
        }
        return max(rob, not_rob);
    }
    int rob(vector<int>& nums) {
        if(nums.size() <= 2){
            return max(nums[0], nums[nums.size() - 1]);
        }
        return max(easy_rob(nums, 0, nums.size() - 2), easy_rob(nums, 1, nums.size() - 1));
    }
};