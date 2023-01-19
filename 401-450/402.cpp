class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size(), deleted = 0;
        vector<char> s;
        
        for(auto i: num){
            while(!s.empty() && s.back() > i && k > 0){
                s.pop_back();
                --k;
            }
            s.push_back(i);
        }
        
        while(k > 0){
            s.pop_back();
            --k;
        }
        
        string ans = "";
        bool leading = true;
        for(auto c: s){
            if(leading && c == '0'){
                continue;
            }
            leading = false;
            ans += c;
        }
        
        return ans == "" ? "0" : ans;
    }
};