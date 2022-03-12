class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> dict;
        dict[0] = 1;
        int sum = 0;
        int ans = 0;
        for(auto i: nums){
            sum += i;
            if(dict.find(sum - k) != dict.end())
                ans += dict[sum - k];
            dict[sum]++;
        }
        return ans;
    }
};