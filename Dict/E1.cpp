class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>dict;
        for(int i = 0; i < n; i++){
            dict[nums[i]] = i;
        }
        for(int i = 0; i < n; i++){
            if(dict.find(target - nums[i]) != dict.end() && dict[target - nums[i]] != i){
                return {i, dict[target - nums[i]]};
            }
        }
        return {0, 0};
    }
};