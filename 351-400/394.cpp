class Solution {
public:
    string decodeString(const string& s){
        string ans;
        stack<int> nums;
        stack<string> strs;
        int n = s.size(), num = 0;

        for(auto ch: s){
            if(ch >= '0' && ch <= '9'){
                num = num * 10 + ch - '0';
            }
            else if(isalpha(ch)){
                ans += ch;
            }
            else if(ch == '['){
                nums.push(num);
                num = 0;
                strs.push(ans);
                ans = {};
            }
            else{
                int m = nums.top();
                nums.pop();
                for(int i = 0; i < m; ++i){
                    strs.top() += ans;
                }
                ans = strs.top();
                strs.pop();
            }
        }
        return ans;
    }
};