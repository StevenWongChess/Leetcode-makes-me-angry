class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128, 0);
        vector<bool> isset(128, false);
        for(auto i: t){
            ++cnt[i];
            isset[i] = true;
        }

        int n = s.length();
        int l = 0, start = 0, length = INT_MAX, count = t.size();
        for(int r = 0; r < n; ++r){
            if(isset[s[r]]){
                --cnt[s[r]];
                if(cnt[s[r]] >= 0){
                    --count;
                }
                while(count == 0){
                    if(r - l + 1 < length){
                        length = r - l + 1;
                        start = l;
                    }
                    if(isset[s[l]]){
                        ++cnt[s[l]];
                        if(cnt[s[l]] > 0)
                            ++count;
                    }
                    ++l;
                }
            }
        }
        return length == INT_MAX ? "" : s.substr(start, length);
    }
};