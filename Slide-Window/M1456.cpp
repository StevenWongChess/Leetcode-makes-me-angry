class Solution {
public:
    bool isVowel(char c){
        for(auto i: "aeiou"){
            if(c == i)
                return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int count = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(isVowel(s[i]))
                count++;
            if(i >= k && isVowel(s[i - k]))
                count--;
            ans = max(ans, count);
        }        
        return ans;
    }
};