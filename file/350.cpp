class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        int n = nums2.size();
        int l = 0;
        int r = 0;
        while(l < m && r < n){
            if(nums1[l] == nums2[r]){
                ans.push_back(nums1[l]);
                l++; r++;
            }
            else if(nums1[l] > nums2[r])
                r++;
            else
                l++;
        }
        return ans;
    }
};