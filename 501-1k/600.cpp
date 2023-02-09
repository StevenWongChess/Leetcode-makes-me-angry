class Solution {
public:
    vector<int> v;
    int cnt_digits(int n ){
        int digits = 0;
        while(n){
            ++digits;
            n >>= 1;
        }
        return digits;
    }
    int count(int n){
        int m = cnt_digits(n);
        if(n <= 1)
            return n + 1;
        if(n <= 3)
            return 3;
        int div = (1 << (m - 2));
        if(n / div == 3)
            return v[m - 2] + v[m - 3];
        else
            return v[m - 2] + count(n % div);
    }

    int findIntegers(int n) {
        int digits = cnt_digits(n);
        v = {2, 3};
        for(int i = 1; i < digits; ++i){
            v.push_back(v[i] + v[i - 1]);
        }
        return count(n);
    }
};