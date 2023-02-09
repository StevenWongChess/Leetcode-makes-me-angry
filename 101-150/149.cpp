class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i = 0; i < n; ++i){
            unordered_map<int, int> dict;
            for(int j = 0; j < n; ++j){
                if(i != j){
                    int dx = points[i][0] - points[j][0], dy = points[i][1] - points[j][1];
                    int gcd_ = gcd(dx, dy);
                    dx /= gcd_, dy /= gcd_;
                    if(dx == 0)
                        dy = 1;
                    ++dict[dx + dy * 20000];
                }
            }
            for(auto [k, cnt]: dict){
                ans = max(ans, cnt);
            }
        }
        return ans > 1 ? ans + 1 : min(n, 2);
    }
};