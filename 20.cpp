class Solution {
public:
    int char_to_num(char c){
        if(c == '(')
            return 1;
        if(c == '[')
            return 2;
        if(c == '{')
            return 3;
        if(c == ')')
            return 6;
        if(c == ']')
            return 5;
        if(c == '}')
            return 4;
        return -1;
    }
    bool isValid(string s) {
        stack<int> q;
        for(auto i: s){
            int num = char_to_num(i);
            if(num <= 3)
                q.push(num);
            else if(q.empty() ||q.top() + num != 7)
                return false;
            else
                q.pop();
        }
        return q.empty();
    }
};