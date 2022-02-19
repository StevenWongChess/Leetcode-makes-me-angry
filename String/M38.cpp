class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++){
            string tmp;
            int m = ans.length();
            int count = 0;
            int number = -1;
            for(auto j: ans){
                if(j == number + '0'){
                    count++;
                }
                else{
                    if(number != -1)
                        tmp += (to_string(count) + (char)(number + '0'));
                    number = j - '0';
                    count = 1;
                }
            }
            if(number != -1)
                tmp += (to_string(count) + (char)(number + '0'));
            ans = tmp;
        }
        return ans;
    }
};