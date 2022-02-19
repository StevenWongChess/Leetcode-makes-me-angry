class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        dict[0] = 1;
        int prefix = 0;
        int ans = 0;
        for(auto i: nums){
            prefix += i;
            if(dict.find(prefix - k) != dict.end())
                ans += dict[prefix - k];
            dict[prefix]++;
        }
        return ans;
    }
};