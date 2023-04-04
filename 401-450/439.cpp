class Solution {
public:
    string parseTernary(string expression) {
        expression.push_back(':');
        for(int i = 0, d = 0;; i += 2){
            if(expression[i + 1] == '?'){
                d += d || expression[i] == 'F';
            }
            else{
                --d;
                if(d < 0)
                    return {expression[i]};
            }
        }
        return {};
    }
};