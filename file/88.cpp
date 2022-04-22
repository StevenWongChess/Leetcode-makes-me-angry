class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m - 1; 
        int r = n - 1;

        for(int i = m + n - 1; i >= 0; i--){
            int a = (l >= 0 ? nums1[l] : INT_MIN);
            int b = (r >= 0 ? nums2[r] : INT_MIN);
            if(a > b){
                nums1[i] = a;
                l--;
            }
            else{
                nums1[i] = b;
                r--; 
            }
        }
    }
};