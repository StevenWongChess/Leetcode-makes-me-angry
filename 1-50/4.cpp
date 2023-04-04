class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int l = 0; int r = m;
        while(l <= r){
            int mid = (l + r) / 2;
            int div = (m + n + 1) / 2 - mid;

            int a = mid == 0 ? INT_MIN : nums1[mid - 1];
            int b = mid == m ? INT_MAX : nums1[mid];
            int c = div == 0 ? INT_MIN : nums2[div - 1];
            int d = div == n ? INT_MAX : nums2[div];
            
            if(max(a, c) <= min(b, d))
                return (m + n) & 1 ? max(a, c) : (max(a,c) + min(b, d)) / 2.0;
            else if(a < c)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;

    }
};