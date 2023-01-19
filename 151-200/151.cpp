class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // deal with blank space in between
        int it = 0;
        bool flag = true; // indicate if last is blank
        for(int i = 0; i < n; ++i){
            if(s[i] == ' '){
                if(!flag){
                    flag = true;
                    s[it] = ' ';
                    ++it;
                }
            }   
            else{
                flag = false;
                auto tmp = s[i];
                s[i] = ' ';
                s[it] = tmp;
                ++it;
            }          
        }

        int a = 0, b = 0;
        it = 0;
        while(it < n && s[it] == ' '){
            ++a; ++it;
        }
        it = n - 1;
        while(it >= 0 && s[it] == ' '){
            ++b; --it;
        }

        int l = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == ' '){
                reverse(s.begin() + l, s.begin() + i);
                l = i + 1;
            }
        }
        if(s[n - 1] != ' ')
            reverse(s.begin() + l, s.end());
        reverse(s.begin(), s.end());
        return s.substr(b, n - a - b);
    }
};