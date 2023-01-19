class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0, n = heaters.size();
        sort(heaters.begin(), heaters.end());
        
        for(auto h: houses){
            int r = upper_bound(heaters.begin(), heaters.end(), h) - heaters.begin(), l = r - 1;
            int rd = r >= n ? INT_MAX : heaters[r] - h, ld = l < 0 ? INT_MAX : h - heaters[l];
            ans = max(ans, min(rd, ld));
        }
        
        return ans;
    }
};