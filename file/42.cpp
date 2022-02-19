class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        int l_max = 0;
        int r_max = 0;
        while(l < r){
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);
            if(height[l] > height[r]){
                ans += r_max - height[r];
                r--;
            }
            else{
                ans += l_max - height[l];
                l++;
            }
        }
        return ans;
    }
};