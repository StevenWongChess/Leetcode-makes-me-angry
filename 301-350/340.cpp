class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> v;
        int n = s.size();
        int l = 0;
        int count = 0, ans = 0;
        
        for(int r = 0; r < n; ++r){
            ++v[s[r] - 'a'];
            if(v[s[r] - 'a'] == 1){
                ++count;
            }
            while(count > k && l <= r){
                --v[s[l] - 'a'];
                if(v[s[l] - 'a'] == 0){
                    --count;
                }
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};