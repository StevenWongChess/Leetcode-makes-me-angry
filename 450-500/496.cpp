class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> dict;
        stack<int> s;
        
        for(int i = n - 1; i >= 0; --i){
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }
            dict[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> ans(m);
        for(int i = 0; i < m; ++i){
            ans[i] = dict[nums1[i]];
        }
        
        return ans;
    }
};