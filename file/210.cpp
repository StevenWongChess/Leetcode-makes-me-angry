class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses, (vector<int>){});
        vector<int> inflow(numCourses, 0);
        vector<int> ans;
        queue<int> q;
        for(auto i: prerequisites){
            edge[i[1]].push_back(i[0]);
            inflow[i[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(inflow[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            for(auto j: edge[i]){
                inflow[j]--;
                if(inflow[j] == 0){
                    q.push(j);
                    ans.push_back(j);
                }
            }
        }
        return (ans.size() == numCourses) ? ans : (vector<int>){};
    }
};