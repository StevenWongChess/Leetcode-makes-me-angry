class Solution {
public:
    int dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
        int n = isConnected.size();
        if(!visited[i]){
            visited[i] = true;
            for(int j = 0; j < n; j++){
                if(isConnected[i][j])
                    dfs(isConnected, j, visited);
            }
            return 1;
        }
        else
            return 0;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            count += dfs(isConnected, i, visited);
        }
        return count;
    }
};


class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited){
        int n = isConnected.size();
        if(visited[i])
            return;
        visited[i] = true;
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            if(isConnected[i][j] == 1)
                dfs(j, isConnected, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};