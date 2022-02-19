class Solution {
public:
    int sum(int n){
        int ans = 0;
        while(n > 0){
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        if(n == 1)
            return true;
        int slow = sum(n);
        int fast = sum(sum(n));
        while(slow != fast){
            if(slow == 1){
                return true;
            }
            slow = sum(slow);
            fast = sum(sum(fast));
        }
        return slow == 1;
    }
};