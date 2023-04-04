class Solution {
public:
    unordered_map<string, string> map = {
        {"1", "1"}, {"6", "9"}, {"9", "6"}, {"8", "8"}
    };

    int strobogrammaticInRange(string low, string high) {
        // auto l = stol(low), r = stol(high);
        int n = max(2, static_cast<int>(high.size())); 
        // vector<vector<string>> v(n + 1);
        vector<set<string>> v(n + 1);
        v[0] = {""};
        v[1] = {"0", "1", "8"};
        v[2] = {"11", "88", "69", "96"};
        for(int i = 3; i <= n; ++i){
            for(auto s: v[i - 2]){
                for(auto [x, y]: map){
                    // v[i].push_back(x + s + y);
                    v[i].insert(x + s + y);
                }
            }
            if(i >= 4){
                for(auto s: v[i - 2]){
                    for(auto [x, y]: map){
                        string tmp = x + s + y;
                        tmp[1] = tmp[tmp.size() - 2] = '0';
                        // v[i].push_back(tmp);
                        v[i].insert(tmp);
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            for(auto s: v[i]){
                // if(s >= low && s <= high)
                if(stol(s) >= stol(low) && stol(s) <= stol(high)){
                    cout << stol(s) << ", ";
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};