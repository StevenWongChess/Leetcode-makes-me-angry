class Solution {
public:
    int countPrimes(int n) {
        // int count = 0;
        vector<int> prime;
        vector<bool> isprime(n, true);
        for(int i = 2; i < n; i++){
            if(isprime[i]){
                prime.push_back(i);
            }
            for(int j = 0; j < prime.size() && prime[j] * i < n; j++){
                isprime[prime[j] * i] = false;
                if(i % prime[j] == 0)
                    break;
            }
        }
        return prime.size();
    }    
};