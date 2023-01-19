class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        int base = *min_element(nums.begin(), nums.end());
        for(auto i: nums){
            ans += i - base;
        }
        
        return ans;
    }
};