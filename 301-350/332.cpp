class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> dict;
    vector<string> s;
    void dfs(const string& str){
        while(dict.count(str) && dict[str].size() > 0){
            string tmp = dict[str].top();
            dict[str].pop();
            dfs(tmp);
        }
        s.push_back(str);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& i: tickets){
            dict[i[0]].push(i[1]);
        }  
        dfs("JFK");

        reverse(s.begin(), s.end());
        return s;
    }
};