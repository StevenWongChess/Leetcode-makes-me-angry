class Solution {
public:
    int rob(vector<int>& v){
        int rob = 0, nrob = 0;
        for(auto i: v){
            int tmp = nrob;
            nrob = max(rob, nrob);
            rob = max(rob, tmp + i);
        }
        return max(rob, nrob);
    }

    int deleteAndEarn(vector<int>& nums) {
        int max_ = nums[0];
        for(auto i: nums){
            max_ = max(max_, i);
        }

        vector<int> v(max_ + 1);
        for(auto i: nums){
            v[i] += i;
        }
        return rob(v);
    }

    int deleteAndEarn(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> v = {nums[0]};
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i - 1])
                v.back() += nums[i];
            else if(nums[i] == nums[i - 1] + 1)
                v.push_back(nums[i]);
            else{
                ans += rob(v);
                v = {nums[i]};
            }
        }
        ans += rob(v);
        return ans;
    }
};