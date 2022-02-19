class Solution {
public:
    bool judge(vector<int> dict, vector<int> zero){
        // return dict == zero;
        for(int i = 0; i < dict.size(); i++){
            if(dict[i] != 0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) { 
        vector<int> ans;
        if(s.length() < p.length())
            return ans;
        vector<int> dict(26, 0);
        vector<int> zero(26, 0);
        for(int i = 0; i < p.length(); i++){
            dict[p[i] - 'a']++;
            dict[s[i] - 'a']--;
        }
        // if(judge(dict))
        if(dict == zero)
            ans.push_back(0);
        for(int i = p.length(); i < s.length(); i++){
            dict[s[i] - 'a']--;
            dict[s[i - p.length()] - 'a']++;
            // if(judge(dict)){
            if(dict == zero){
                ans.push_back(i - p.length() + 1);
            }
        }
        return ans;
    }
};