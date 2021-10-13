class Solution {
public:
    int isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            if(i < k)
                sum += isvowel(s[i]);
            else{
                sum += isvowel(s[i]);
                sum -= isvowel(s[i - k]);
            }
            ans = max(ans, sum);
        }  
        return ans;
    }
};