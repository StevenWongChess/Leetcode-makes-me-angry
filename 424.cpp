class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int n = s.length();
        int top = 0;
        int l = 0; int r = 0;
        while(r < n){
            cnt[s[r] - 'A']++;
            top = max(top, cnt[s[r] - 'A']);
            if(r - l + 1 - top > k){
                cnt[s[l] - 'A']--;
                l++; 
            }
            r++;
        }
        return r - l;
    }
};