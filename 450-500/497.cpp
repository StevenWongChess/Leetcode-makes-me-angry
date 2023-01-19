class Solution {
public:
    mt19937 gen{random_device{}()};
    int n;
    vector<vector<int>> &v;
    vector<int> prefix;
    
    
    Solution(vector<vector<int>>& rects): v{rects} {
        n = rects.size();
        prefix.push_back(0);
        for(int i = 0; i < n; ++i){
            int area = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            prefix.push_back(prefix.back() + area);
        }
    }
    
    vector<int> pick() {
        uniform_int_distribution<int> dis(0, prefix.back() - 1);
        int k = dis(gen) % prefix.back();
        auto it = upper_bound(prefix.begin(), prefix.end(), k);
        int index = it - prefix.begin() - 1;
        k -= prefix[index];
        int a = v[index][0], b = v[index][1], x = v[index][2], y = v[index][3];
        return {a + k / (y - b + 1), b + k - (y - b + 1) * (k / (y - b + 1))};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */