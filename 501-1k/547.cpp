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
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        int n = isConnected.size();
        visited[i] = true;
        for(int j = 0; j < n; ++j){
            if(i == j)
                continue;
            if(isConnected[i][j] == 1 && !visited[j])
                dfs(isConnected, visited, j);
        }   
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                ++ans;
                dfs(isConnected, visited, i);
            }
        }
        return ans;
    }
};