class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        bool all_A = true;
        bool all_a = true;
        for(int i = 1; i < n; i++){
            if(islower(word[i]))
                all_A = false;
            if(isupper(word[i]))
                all_a = false;
        }
        return isupper(word[0]) && all_A || all_a;
    }
};