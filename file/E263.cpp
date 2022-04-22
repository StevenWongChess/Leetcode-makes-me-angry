class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        vector<int> list{2, 3, 5};
        for(auto i: list){
            while(n % i == 0){
                n /= i;
            }
        }
        return n == 1;
    }
};