class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>dict;
        for(auto i: s){
            dict[i]++;
        }
        int odd = 0;
        int ans = 0;
        for(auto [x, y]: dict){
            if(y % 2 == 1)
                odd = 1;
            ans += y / 2;
        }
        return odd + ans * 2;
    }
};