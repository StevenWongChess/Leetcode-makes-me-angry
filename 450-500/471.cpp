class Solution {
public:
    vector<vector<string>> f;
    string encode(string s) {
        int n = s.size();
        f = vector<vector<string>> (n, vector<string>(n));
        for(int len = 1; len <= n; len ++)
            for(int i = 0;  i + len - 1 < n; i ++){
                int j = i + len - 1;
                f[i][j] = sub_str(s, i, j); 
                if(len > 4){
                    for(int k = i; k < j; k ++){ 
                        string tmp = f[i][k] + f[k + 1][j];
                        if(f[i][j].size() > tmp.size()) 
                            f[i][j] = tmp;
                    }
                }
            }

        return f[0][n - 1];  

    }

    string sub_str(string s, int i, int j){
        s = st.substr(i, j - i + 1);
        if(s.size() < 5) 
            return s;
        int p = (s + s).find(s, 1); 
        if(p != s.size())      
            return to_string(s.size() / p) + "[" + f[i][i + p - 1] + "]";
        else
            return s;
    }
};