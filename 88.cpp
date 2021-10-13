class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int pos = m + n - 1;
        while(pos >= 0){
            if(i >= 0 && j >= 0){
                if(nums1[i] >= nums2[j]){
                    swap(nums1[i], nums1[pos]);
                    i--;
                }
                else{
                    swap(nums2[j], nums1[pos]);
                    j--;
                }
            }
            else if(j < 0)
                break;
            else{
                swap(nums2[j], nums1[pos]);
                j--;
            }
            pos--;
        }
    }
};