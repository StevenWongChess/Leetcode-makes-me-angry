class Solution {
public:
    int char_to_num(char c){
        if(c == 'I')
            return 1;
        else if(c == 'V')
            return 5;
        else if(c == 'X')
            return 10;
        else if(c == 'L')
            return 50;
        else if(c == 'C')
            return 100;
        else if(c == 'D')
            return 500;
        else
            return 1000;
    }
    int romanToInt(string s) {
        int ans = 0;
        int prev = INT_MAX;
        for(int i = 0; i < s.length(); i++){
            int num = char_to_num(s[i]);
            if(num > prev)
                ans += (num - 2 * prev);
            else   
                ans += num;
            prev = num;
        }
        return ans;
    }
};