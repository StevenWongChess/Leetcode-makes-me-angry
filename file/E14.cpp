class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto s1 = *max_element(strs.begin(), strs.end());
        auto s2 = *min_element(strs.begin(), strs.end());
        string ans = "";
        int len = s1.length();
        for(int i = 0; i < len; i++){
            if (s1[i] != s2[i]){
                return s2.substr(0, i);
            }
        }
        return s1;
        // int min_length = INT_MAX;
        // for(int i = 0; i < strs.size(); i++){
        //     min_length = min(min_length, (int)strs[i].length());
        // }
        // string ans = "";
        // for(int i = 0; i < min_length; i++){
        //     bool flag = true;
        //     for(int j = 0; j < strs.size(); j++){
        //         if(strs[0][i] != strs[j][i])
        //             flag = false;
        //     }
        //     if(flag)
        //         ans += strs[0][i];
        //     else
        //         return ans;
        // }
        // return ans;
    }
};