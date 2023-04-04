class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool lower_flag = false, upper_flag = false, digit_flag = false;

        for(auto ch: password){
            if(islower(ch))
                lower_flag = true;
            else if(isupper(ch))
                upper_flag = true;
            else if(isdigit(ch))
                digit_flag = true;
        }

        int satisfy = lower_flag + upper_flag + digit_flag;
        if(n < 6){
            return max(6 - n, 3 - satisfy);
        }
        else if(n <= 20){
            int replace = 0, cnt = 0;
            char last = '#';
            for(auto ch: password){
                if(ch == last){
                    ++cnt;
                }
                else{
                    replace += cnt / 3;
                    cnt = 1;
                    last = ch;
                }
            }
            replace += cnt / 3;
            return max(replace, 3 - satisfy);
        }
        else{
            int replace = 0, remove = n - 20, cnt = 0;
            int rm2 = 0;
            char last = '#';
            for(auto ch: password){
                if(ch == last){
                    ++cnt;
                }
                else{
                    if(remove > 0 && cnt >= 3){
                        if(cnt % 3 == 0){
                            --remove;
                            --replace;
                        }
                        else if(cnt % 3 == 1){
                            ++rm2;
                        }
                    }

                    replace += cnt / 3;
                    cnt = 1;
                    last = ch;
                }
            }
            if(remove > 0 && cnt >= 3){
                if(cnt % 3 == 0){
                    --remove;
                    --replace;
                }
                else if(cnt % 3 == 1){
                    ++rm2;
                }
            }
            replace += cnt / 3;
            
            int use2 = min({replace, rm2, remove / 2});
            replace -= use2;
            remove -= use2 * 2;

            int use3 = min({replace, remove / 3});
            replace -= use3;
            remove -= use3 * 3;
            
            return (n - 20) + max(replace, 3 - satisfy);
        }
    }
};














