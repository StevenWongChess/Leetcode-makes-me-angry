class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int ans = 0;
        for(int i = 1; i <= 26; i++){
            unordered_map<char, int> dict;
            int kind = 0;
            int satisfy = 0;
            int l = 0; int r = 0;
            while(r < n){
                dict[s[r]]++;
                if(dict[s[r]] == 1)
                    kind++;
                if(dict[s[r]] == k)
                    satisfy++;
                while(kind > i){
                    dict[s[l]]--;
                    if(dict[s[l]] == k - 1)
                        satisfy--;
                    if(dict[s[l]] == 0){
                        kind--;
                    }
                    l++;
                }
                if(i == satisfy)
                    ans = max(ans, r - l + 1);  
                r++;
            }
        }
        return ans;
    }
};
