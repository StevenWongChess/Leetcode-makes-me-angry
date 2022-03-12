class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            if(s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
            if(s.size() > k)
                s.erase(nums[i - k]);
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> dict;
        for(int i = 0; i < n; i++){
            if(dict.find(nums[i]) != dict.end()){
                int last = dict[nums[i]];
                if(i - last <= k)
                    return true;
                dict[nums[i]] = i;
            }
            else{
                dict[nums[i]] = i;
            }
        }
        return false;
    }
};