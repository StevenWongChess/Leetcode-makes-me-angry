class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1, 0);
        for(int i = 1; i <= n; i++){
            int least = INT_MAX;
            for(int j = 1; j * j <= i; j++){
                least = min(least, v[i - j * j] + 1);
            }
            v[i] = least;
        }
        return v[n];
    }
};