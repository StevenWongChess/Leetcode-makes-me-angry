class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict; 
        for(int i = 0; i < nums.size(); i++){
            dict[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(dict.find(target - nums[i]) != dict.end() && i != dict[target - nums[i]]){
                return {i, dict[target - nums[i]]};
            }
        }
        return {};
    }
};