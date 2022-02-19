class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(auto i: columnTitle){
            ans *= 26;
            ans += (int)(i - 'A' + 1);          
        }
        return ans;
    }
};