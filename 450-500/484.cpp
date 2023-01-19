class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size() + 1;
        vector<int> v(n);
        
        for(int i = 0; i < n; ++i){
            v[i] = i + 1;
        }
        
        int l = -1;
        bool flag = false;
        
        for(int i = 0; i < n - 1; ++i){
            if(s[i] == 'I'){
                reverse(v.begin() + l + 1, v.begin() + i + 1); 
                l = i;
                flag = false;
            }
            else{
                flag = true;
            }
        }
        if(flag){
            reverse(v.begin() + l + 1, v.end());
        }
        
        return v;
    }
};