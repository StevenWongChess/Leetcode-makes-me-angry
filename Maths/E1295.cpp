class Solution {
public:
    int digits(int n){
        int ans = 0;
        while(n){
            ans++;
            n /= 10;
        }
        return ans;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i: nums){
            if(digits(i) % 2 == 0)
                ans++;
        }
        return ans;
    }
};