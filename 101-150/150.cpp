class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token: tokens){
            if(token.size() == 1 && !isdigit(token[0])){
                // operator
                auto b = s.top(); s.pop();
                auto a = s.top(); s.pop();
                if(token == "+")
                    s.push(a + b);
                else if(token == "-")
                    s.push(a - b);
                else if(token == "*")
                    s.push(a * b);
                else
                    s.push(a / b);
            }
            else{
                int num = 0, neg = 1;
                for(auto ch: token){
                    if(ch == '-'){
                        neg = -1;
                        continue;
                    }
                    num = 10 * num + ch - '0';
                }
                s.push(num);
            }
        }
        return s.top();
    }
};