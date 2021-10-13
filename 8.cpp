class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int ans = 0;
        int flag = 1;
        while(i < n && s[i] == ' '){
            i++;
        }
        if(i >= n){
            return ans;
        }
        if(s[i] == '-'){
            flag = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        // else{}
        while(i < n){
            if('0' <= s[i] && s[i] <= '9' ){
                if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > 7))
                    return flag == 1 ? INT_MAX : INT_MIN;
                ans *= 10;
                ans += (s[i] - '0');
                i++;
            }
            else
                return flag * ans;
        }
        return flag * ans;
    }
};