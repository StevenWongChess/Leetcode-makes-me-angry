class Solution {
public:
    int countPrimes(int n) {
//         if(n < 2)
//             return 0;
//         vector<bool> dp(n, true);
//         vector<int> primes;
//         for(int i = 2; i < n; ++i){
//             if(dp[i]){
//                 primes.push_back(i);
//             }
//             for(int j = 0; j < primes.size() && primes[j] * i < n; ++j){
//                 dp[primes[j] * i] = false;
//                 if(i % primes[j] == 0){
//                     break;
//                 }
//             }
//         }
        
//         return primes.size();
        
        vector<bool> dp(n, true);
        if(n < 2)
            return 0;
        
        dp[2] = true;

        for(int i = 2; i < n; ++i){
            if(dp[i] == true){
                for(int j = 2 * i; j < n; j += i){
                    dp[j] = false;
                }
            }
        }
        int count = -2;
        for(auto i: dp){
            if(i)
                ++count;
        }
        return count;
    }
};