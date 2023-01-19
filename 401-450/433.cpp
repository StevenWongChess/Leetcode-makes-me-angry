class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> pool, visited;
        string option = "ACGT";
        for(auto &i: bank){
            pool.insert(i);
        }
        
        if(startGene == endGene)
            return 0;
        if(!pool.count(endGene))
            return -1;
        
        queue<pair<string, int>> q;
        q.push({startGene, 1});
        visited.insert(startGene);
        // int step = 1;
        while(!q.empty()){
            auto [s, step] = q.front();
            q.pop();
            for(int i = 0; i < 8; ++i){
                for(auto &ch:option){
                    string next = s;
                    next[i] = ch;
                    if(!visited.count(next) && pool.count(next)){
                        if(next == endGene){
                            return step;
                        }
                        q.push({next, step + 1});
                        visited.insert(next);
                    }
                }
            }
        }
        
        return -1;
    }
};