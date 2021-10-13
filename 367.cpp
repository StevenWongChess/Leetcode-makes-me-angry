class Solution {
public:
    bool isPerfectSquare(int num) {
        // binary search also works
        int i = 1;
        while(num > 0){
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};