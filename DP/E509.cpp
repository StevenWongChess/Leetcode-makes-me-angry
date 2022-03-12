class Solution {
public:
    int fib(int n) {
        int first = 0;
        int second = 1;
        for(int i = 0; i < n; i++){
            first += second;
            swap(first, second);
        }
        return first;
    }
};