class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int L = 1;
        for(int i = 1; i < n; i++){
            L *= nums[i - 1];
            ans[i] = L;
        }
        int R = 1;
        for(int i = n - 2; i >= 0; i--){
            R *= nums[i + 1];
            ans[i] *= R;
        }
        return ans;
    }
};