class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count = 0, n = s.size();
        string newstr(n, ' ');
        for(auto i:s){
            if(i != '-'){
                newstr[count] = toupper(i);
                ++count;
            }
        }
        if(count == 0){
            return "";
        }
        
        string ans(count + static_cast<int>((count + k - 1) / k) - 1, ' ');
        int it = ans.size() - 1, cnt = 0;
        for(int i = count - 1; i >= 0; --i){
            ans[it] = newstr[i];
            --it;
            ++cnt;
            if(cnt % k == 0 && it >= 0){
                ans[it] = '-';
                --it;
            }
        }
        
        return ans;
    }
};