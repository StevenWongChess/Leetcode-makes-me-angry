class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size(), m = abbr.size();
        int j = 0, count = 0;
        for(int i = 0; i < m; ++i){
            if(j >= n){
                return false;
            }
            if(abbr[i] >= 'a' && abbr[i] <= 'z'){
                count = 0;
                if(word[j] != abbr[i])
                    return false;
                ++j;
            }
            else{
                if(abbr[i] == '0' && (i == 0 || (abbr[i - 1] <= 'z' && abbr[i - 1] >= 'a')))
                    return false;
                count = 10 * count + abbr[i] - '0';
                if(i == m - 1 || (abbr[i + 1] <= 'z' && abbr[i + 1] >= 'a'))
                    j += count;
            }
        }
        return j == n;
    }
};