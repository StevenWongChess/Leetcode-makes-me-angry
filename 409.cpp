class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0; int flag = 0;
        unordered_map<char, int> count;
        for(auto i: s){
            count[i]++;
        }
        for(auto i:count){
            if(i.second % 2 == 1)
                flag = 1;
            ans += (i.second / 2) * 2;
        }
        return ans + flag;
    }
};