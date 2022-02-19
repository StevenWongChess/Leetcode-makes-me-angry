// The above one is optimized while the below one is more intuitive solution.

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128, 0);
        vector<bool> isset(128, false);
        for(auto i: t){
            cnt[i]++;
            isset[i] = true;
        }
        int n = s.length();
        int l = 0; int r = 0;
        int mini = INT_MAX;
        int start = 0; int flag = 0;
        while(r < n){
            if(isset[s[r]]){
                cnt[s[r]]--;
                if(cnt[s[r]] >= 0)
                    flag++;
                while(flag == t.length()){
                    if(r - l + 1 < mini){
                        mini = r - l + 1;
                        start = l;
                    }
                    if(isset[s[l]]){
                        cnt[s[l]] ++;
                        if(cnt[s[l]] > 0)
                            flag--;
                    }
                    l++;
                }
            }
            r++;
        }
        return mini == INT_MAX ? "" : s.substr(start, mini);
    }
};

// class Solution {
// public:
//     vector<int> cnt = vector<int>(128, 0);
//     bool check(){
//         for(auto i: cnt){
//             if(i > 0)
//                 return false;
//         }
//         return true;
//     }
//     string minWindow(string s, string t) {
//         for(auto i: t){
//             cnt[i]++;
//         }
//         for(auto& i: cnt){
//             if(i == 0){
//                 i = INT_MIN/2;
//             }
//         }
//         int n = s.length();
//         int l = 0; int r = 0;
//         int mini = INT_MAX;
//         int start = 0;
//         while(r < n){
//             cnt[s[r]]--;
//             while(check()){
//                 if(r-l+1 < mini){
//                     mini = r-l+1;
//                     start = l;
//                 }
//                 cnt[s[l]]++;
//                 l++;
//             }
//             r++;
//         }
//         return mini == INT_MAX ? "" : s.substr(start, mini);
//     }
// };