class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> edge(n);
        vector<int> inflow(n, 0);
        queue<int> q;
        int visited = 0;

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
            ++visited;
            for(auto next: edge[idx]){
                --inflow[next];
                if(inflow[next] == 0){
                    q.push(next);
                }
            }
        }
        return visited == n;
    }
};