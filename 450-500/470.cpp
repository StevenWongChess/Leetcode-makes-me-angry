// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = 10, b = 10;
        
        while(a > 6){
            a = rand7();
        }
        while(b > 5){
            b = rand7();
        }
        
        return (a % 2) * 5 + b;
    }
};