class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int l = j + 1; int r = n - 1;
                while(l < r){
                    if(nums[i] + nums[j] == target - nums[l] - nums[r]){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l + 1]) l++;
                        while(l < r && nums[r] == nums[r - 1]) r--;
                        l++; r--;
                    }
                    else if(nums[i] + nums[j] > target - nums[l] - nums[r])
                        r--;
                    else    
                        l++;
                }
            }
        }
        return ans;
    }
};