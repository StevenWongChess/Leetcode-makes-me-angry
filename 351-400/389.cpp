class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for(auto i: s){
            ans ^= i;
        }
        for(auto i: t){
            ans ^= i;
        }
        return ans;
    }
};