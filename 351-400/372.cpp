class Solution {
public:
    const int MOD = 1337;
    long pow(long x, int n){
        int ans = 1;
        while(n){
            if(n % 2 == 1){
                ans = ans * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        int n = b.size();
        long ans = 1;
        long x = a;
        for(int i = n - 1; i >= 0; --i){
            ans = ans * pow(x, b[i]) % MOD;
            x = pow(x, 10);
        }
        return static_cast<int>(ans);
    }
};