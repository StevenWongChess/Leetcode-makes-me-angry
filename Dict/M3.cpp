class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        int l = 0;
        unordered_map<char, int>dict;
        for(int i = 0; i < n; i++){
            dict[s[i]]++;
            if(dict[s[i]] == 1){
                ans = max(ans, i - l + 1);
                continue;
            }
            else{
                while(dict[s[i]] > 1){
                    dict[s[l]]--;
                    l++;
                }
            }
        }
        return ans;
    }
};