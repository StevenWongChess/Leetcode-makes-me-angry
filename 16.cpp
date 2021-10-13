class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int gap = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int l = i + 1; int r = n - 1;
            while(l < r){
                int diff = target - nums[i] - nums[l] - nums[r];
                if(abs(diff) < gap){
                    gap = abs(diff);
                    ans = target - diff;
                }
                if(diff == 0)
                    return target;
                else if(diff > 0)
                    l++;
                else    
                    r--;
            }
        }
        return ans;
    }
};