class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // [0, 1] means 1->0
        int n = numCourses;
        vector<vector<int>> edge(n);
        vector<int> inflow(n, 0), ans;
        queue<int> q;
        for(auto i: prerequisites){
            edge[i[1]].push_back(i[0]);
            ++inflow[i[0]];
        }
        for(int i = 0; i < n; ++i){
            if(inflow[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            auto idx = q.front();
            q.pop();
            ans.push_back(idx);
            for(auto next: edge[idx]){
                --inflow[next];
                if(inflow[next] == 0)
                    q.push(next);
            }
        }
        return ans.size() < n ? vector<int>{} : ans;
    }
};