class Solution {
public:
    void writeTo(vector<char>& chars, char last, int cnt, int &it){
        chars[it] = last;
        ++it;
        if(cnt > 1){
            auto tmp = cnt, digits = 0;
            while(tmp){
                ++digits;
                tmp /= 10;
            }
            for(int i = 0; i < digits; ++i){
                chars[it + digits - i - 1] = (cnt % 10 + '0');
                cnt /= 10;
            }
            it += digits;
        }
    }
    
    int compress(vector<char>& chars) {
        int n = chars.size();
        char last = chars[0];
        int cnt = 1, it = 0;
        for(int i = 1; i < n; ++i){
            if(chars[i] == last){
                ++cnt;
            }
            else{
                writeTo(chars, last, cnt, it);
                // update
                last = chars[i];
                cnt = 1;
            }
        }
        writeTo(chars, last, cnt, it);
        for(auto i: chars){
            cout << i << ", ";
        }
        return it;
    }
};

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), it = 0, left = 0;
        
        for(int i = 0; i < n; ++i){
            if(i == n - 1 || chars[i] != chars[i + 1]){
                chars[it] = chars[i];
                ++it;
                int num = i - left + 1;
                if(num > 1){
                    int tmp = it;
                    while(num > 0){
                        chars[it] = num % 10 + '0';
                        ++it;
                        num /= 10;
                    }
                    reverse(chars.begin() + tmp, chars.begin() + it);
                }
                left = i + 1;
            }
        }
        
        return it;
    }
};