class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int l = 0;
        int r = 0;
        while(l < m && r < n){
            if(nums1[l] == nums2[r]){
                if(ans.empty() || ans.back() != nums1[l])
                    ans.push_back(nums1[l]);
                l++; r++;
            }
            else if(nums1[l] < nums2[r])
                l++;
            else
                r++;
        }
        return ans;
    }
};