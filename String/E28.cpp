class Solution {
public:
    int strStr(string haystack, string needle) {
        // return haystack.find(needle);
        int n = haystack.size();
        int m = needle.size();
        if(m == 0)
            return 0;
        vector<int> next(m);
        int j = 0;
        for(int i = 1; i < m; i++){
            while(j > 0 && needle[i] != needle[j]){
                j = next[j - 1];
            }
            if(needle[i] == needle[j]){
                j++;
            }
            next[i] = j;
        }

        j = 0;
        for(int i = 0; i < n; i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == m){
                return i - m + 1;
            }
        }
        return - 1;
    }
};