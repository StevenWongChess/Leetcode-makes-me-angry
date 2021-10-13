class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int length = 0;
        unordered_map<char, int> dict;
        for(int i = 0; i < s.size(); i++){
            if(dict.find(s[i]) == dict.end()){
                dict[s[i]] = i;
                length++;
            }
            else{
                int left = dict[s[i]];
                for(int j = i - length; j < left; j++){
                    dict.erase(s[j]);
                }
                length = i - left;
                dict[s[i]] = i;
            }
            max_length = max(length, max_length);
        }
        return max_length;
    }
};