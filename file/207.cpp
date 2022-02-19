class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses, (vector<int>){});
        vector<int> inflow(numCourses, 0);
        queue<int> q;
        int count = 0;
        for(auto i: prerequisites){
            edge[i[1]].push_back(i[0]);
            inflow[i[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(inflow[i] == 0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            for(auto j: edge[i]){
                inflow[j]--;
                if(inflow[j] == 0){
                    q.push(j);
                    count++;
                }
            }
        }
        return count == numCourses;
    }
};