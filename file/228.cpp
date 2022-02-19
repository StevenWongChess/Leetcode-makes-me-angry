class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans = {};
        if(nums.empty())
            return {};
        int begin = nums[0];
        int end = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == end + 1)
                end++;
            else{
                string s = (begin == end) ? to_string(begin) : (to_string(begin) + "->" + to_string(end));
                ans.push_back(s);
                begin = end = nums[i];
            }
        }
        string s = (begin == end) ? to_string(begin) : (to_string(begin) + "->" + to_string(end));
        ans.push_back(s);
        return ans;
    }
};