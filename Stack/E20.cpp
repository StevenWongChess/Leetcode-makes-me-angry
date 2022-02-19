class Solution {
public:
    bool isValid(string s) {
        stack<int> q;
        unordered_map<char, int> dict{{'(', 1}, {')', 6}, {'[', 2}, {']', 5}, {'{', 3}, {'}', 4}};
        for(auto i: s){
            int num = dict[i];
            if(num <= 3){
                q.push(num);
            }
            else if(q.empty() ||q.top() + num != 7){
                return false;
            }
            else{
                q.pop();
            }
        }
        return q.empty();
    }
};