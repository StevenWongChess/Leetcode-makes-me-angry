class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int l = n - 2;
        int r = n - 1;
        for(int i = 0; i < n; i++){
            if(nums[i] >= 0){
                r = i;
                l = i - 1;
                break;
            }
        }
        while(l >= 0 || r < n){
            if(l < 0){
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
            else if(r >= n){
                ans.push_back(nums[l] * nums[l]);
                l--;   
            }
            else if(abs(nums[l]) <= nums[r]){
                ans.push_back(nums[l] * nums[l]);
                l--;
            }
            else{
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        return ans;
    }
};