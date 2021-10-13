class Solution {
public:
    void reverse(vector<int>& nums, int l, int r){
        for(int i = 0; i <= (r - l) / 2; i++){
            swap(nums[l+i], nums[r-i]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0)
            return;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};