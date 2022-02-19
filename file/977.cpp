class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int l = -1;
        int r = n;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0)
                l = i;
        }
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] >= 0)
                r = i;
        }
        for(int i = 0; i < n; i++){
            if(l < 0){
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
            else if(r >= n){
                ans.push_back(nums[l] * nums[l]);
                l--;
            }
            else if(nums[l] * nums[l] > nums[r] * nums[r]){
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
            else{
                ans.push_back(nums[l] * nums[l]);
                l--;
            }
        }
        return ans;
    }
};