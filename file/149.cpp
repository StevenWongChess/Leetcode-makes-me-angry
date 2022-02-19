class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> dict;
            for(int j = 0; j < n; j++){
                if(i != j){
                    int tmpx;
                    int tmpy;
                    tmpx = points[i][0] - points[j][0];
                    tmpy = points[i][1] - points[j][1];
                    int gcd_ = gcd(tmpx, tmpy);
                    tmpx /= gcd_;
                    tmpy /= gcd_;
                    if(tmpx == 0)
                        tmpy = 1;
                    dict[tmpx + tmpy * 20000]++;
                }
            }
            for(auto i: dict){
                if(i.second > count)
                    count = i.second;
            }
        }
        return count >= 2 ? count + 1 : min(n, 2);
    }
};