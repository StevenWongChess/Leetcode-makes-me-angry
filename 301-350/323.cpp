class Solution
{
public:
    void dfs(vector<int> &visited, int i, vector<vector<int> > &edge_list)
    {
        if (visited[i])
            return;
        visited[i] = true;
        for (auto &e : edge_list[i])
        {
            dfs(visited, e, edge_list);
        }
    }

    int countComponents(int n, vector<vector<int> > &edges)
    {
        vector<int> visited(n, false);
        vector<vector<int> > edge_list(n);
        int count = 0;

        for (auto &e : edges)
        {
            edge_list[e[0]].push_back(e[1]);
            edge_list[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                ++count;
                dfs(visited, i, edge_list);
            }
        }

        return count;
    }
};