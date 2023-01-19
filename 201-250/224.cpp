class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        stack.push(1);
        int n = s.size();
        int ans = 0;
        int sign = 1;
        
        int i = 0;
        while(i < n){
            if(s[i] == ' '){
                ++i;
            }
            else if(s[i] == '+'){
                sign = stack.top();
                ++i;
            }
            else if(s[i] == '-'){
                sign = -stack.top();
                ++i;
            }
            else if(s[i] == '('){
                stack.push(sign);
                ++i;
            }
            else if(s[i] == ')'){
                stack.pop();
                ++i;
            }
            else{
                long num = 0;
                while(i < n && s[i] <= '9' && s[i] >= '0'){
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                ans += num * sign;
            }
        }
        
        return ans;
    }
};