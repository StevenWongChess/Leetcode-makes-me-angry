class Solution {
public:
    vector<int> v;
    int count(int n){
        int digits = count_digits(n);
        if(digits <= 1)
            return n + 1;
        if(digits == 2)
            return 3;
        if((n / (1 << (digits - 2))) > 2)
            return v[digits - 2] + v[digits - 3];
        else
            return v[digits - 2] + count(n % (1 << (digits - 2)));
    }
    int count_digits(int n){
        int digits = 0;
        while(n){
            digits++;
            n >>= 1;
        }
        return digits;
    }
    int findIntegers(int n) {
        int digits = count_digits(n);
        v.push_back(2);
        v.push_back(3);
        for(int i = 2; i <= digits; i++){
            v.push_back(v[i - 1] + v[i - 2]);
        }
        return count(n);
    }
};