class Solution {
public:
    int happy(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int a = n;
        int b = happy(n);
        while(a != b && a != 1){
            a = happy(a);
            b = happy(happy(b));
        }
        return a == 1;
    }
};