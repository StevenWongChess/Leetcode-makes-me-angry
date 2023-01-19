class Solution {
public:
    string smallestGoodBase(string n) {
        long num = stol(n);
        int mMax = floor(log(num) / log(2));
        
        for(int m = mMax; m > 1; --m){
            int k = pow(num, 1.0 / m);
            long mul = 1, sum = 1;
            for(int i = 0; i < m; ++i){
                mul *= k;
                sum += mul;
            }
            if(sum == num){
                return to_string(k);
            }
        }
        
        return to_string(num - 1);
    }
};