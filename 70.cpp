class Solution {
public:
    int climbStairs(int n) {
        int first = 0;
        int second = 1;
        for(auto i = 0; i < n; i++){
            auto tmp = second;
            second += first;
            first = tmp;
        }
        return second;
    }
};

// fast matrix multiplication helps!