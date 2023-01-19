class Solution {
public:
    int magicalString(int n) {
        if(n <= 3){
            return 1;
        }
        
        int l = 2;
        string s = "122";
        while(l < n){
            int r = s.size() - 1;
            if(s[l] == '1'){
                if(s[r] == '1'){
                    s += "2";
                }
                else{
                    s += "1";
                }
            }
            else{
                if(s[r] == '1'){
                    s += "22";
                }
                else{
                    s += "11";
                }
            }
            ++l;
        }
        
        
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1'){
                ++ans;
            }
        }
        return ans;
    }
};