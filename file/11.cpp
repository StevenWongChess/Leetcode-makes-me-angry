class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if(height[l] > height[r])
                r--;
            else
                l++;
        }
        return ans;
    }
};