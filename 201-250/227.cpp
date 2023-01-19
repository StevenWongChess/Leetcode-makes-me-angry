class Solution {
public:
    int calculate(string s) {
        vector<int> stack;
        int n = s.size();
        int num = 0;
        char pre = '+';
        
        for(int i = 0; i < n; ++i){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i == n - 1){
                if(pre == '+'){
                    stack.push_back(num);
                }
                else if(pre == '-'){
                    stack.push_back(-num);
                }
                else if(pre == '*'){
                    stack.back() *= num;
                }
                else{
                    stack.back() /= num;
                }
                pre = s[i];
                num = 0;
            }
                
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};