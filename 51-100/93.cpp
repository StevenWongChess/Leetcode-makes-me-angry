class Solution {
public:
    void dfs(vector<string>& ans, vector<int>& v, int ith, string& s){
        int n = s.size();
        if(ith == n && v.size() == 4){
            ans.push_back(to_string(v[0]) + "." + to_string(v[1]) + "." + to_string(v[2]) + "." + to_string(v[3]));
            return;
        }

        if(ith == n || v.size() == 4)
            return;

        int next = 0;
        for(int i = 0; i < 3; ++i){
            if(next == 0 && i > 0)
                break;
            int digit = s[ith + i] - '0';
            next = 10 * next + digit;
            if(next > 255)
                break;
            v.push_back(next);
            dfs(ans, v, ith + i + 1, s);
            v.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> v;
        dfs(ans, v, 0, s);
        return ans;
    }
};