class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : (num % 9 == 0 ? 9 : num % 9);
        // while(num > 9){
        //     int sum = 0;
        //     while(num){
        //         sum += num % 10;
        //         num /= 10;
        //     }
        //     num = sum;
        // }
        // return num;
    }
};