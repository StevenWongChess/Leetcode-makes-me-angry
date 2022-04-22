class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0)
            return ans;
        int start = nums[0];
        int end = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == end + 1)
                end++;
            else{
                string s = (start == end ? to_string(start) : to_string(start) + "->" + to_string(end));
                ans.push_back(s);
                start = end = nums[i];
            }
        }
        string s = (start == end ? to_string(start) : to_string(start) + "->" + to_string(end));
         ans.push_back(s);  
        return ans;
    }
};