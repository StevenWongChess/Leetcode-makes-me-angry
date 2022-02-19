class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == ' ' && ans == 0)
                continue;
            else if(s[i] == ' ' && ans > 0)
                return ans;
            else    
                ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n - 1;
        while(s[i] == ' '){
            i--;
        }
        int count = 0;
        while(i >= 0 && s[i] != ' '){
            count++;
            i--;
        }
        return count;
    }
};