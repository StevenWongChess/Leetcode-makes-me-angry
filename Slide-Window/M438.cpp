class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int m = s.length(); int n = p.length();
        int count = 0;
        unordered_map<char, int> dict;
        for(auto i: p){
            dict[i]++;
        }
        for(int i = 0; i < m; i++){
            if(dict.find(s[i]) != dict.end()){
                if(dict[s[i]] > 0){
                    dict[s[i]]--; count++;
                }
                else{
                    dict[s[i]]--;
                }
            }
     
            if(i >= n){
                if(dict.find(s[i - n]) != dict.end()){
                    if(dict[s[i - n]] >= 0){
                        dict[s[i - n]]++; count--;
                    }
                    else{
                        dict[s[i - n]]++;
                    }
                }
            }
            if(count == n)
                ans.push_back(i - n + 1);
        }
        return ans;
    }
};


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