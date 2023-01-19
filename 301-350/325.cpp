class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        long prefix = 0;
        unordered_map<long, int> dict;
        for(int i = 0; i < n; ++i){
            prefix += nums[i];
            if(prefix == k)
                ans = i + 1;
            if(dict.find(prefix - k) != dict.end())
                ans = max(ans, i - dict[prefix - k]);
            if(dict.find(prefix) == dict.end())
                dict[prefix] = i;
        }
        return ans;
    }
};