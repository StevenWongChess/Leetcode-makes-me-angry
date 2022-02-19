class Solution {
public:
    bool isVowel(char c){
        string s = "aeiouAEIOU";
        for(auto i: s){
            if(i == c)
                return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int l = 0;
        int r = n - 1;
        while(l < r){
            if(!isVowel(s[l]))
                l++;
            else if(!isVowel(s[r]))
                r--;
            else{
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};