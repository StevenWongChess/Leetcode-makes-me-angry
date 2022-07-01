class Solution
{
public:
    unordered_map<string, vector<pair<string, double> > > graph;
    unordered_map<string, bool> visited;

    double dfs(string src, string dest, double w)
    {
        if (!visited.count(src))
        {
            return -1.0;
        }
        if (src == dest)
            return w;

        visited[src] = true;
        double n_value = -1.0;

        // if(!graph.count(src) || visited[dest])
        // return -1.0;

        for (auto &[x, y] : graph[src])
        {
            if (!visited[x])
            {
                n_value = dfs(x, dest, w * y);
                if (n_value != -1.0)
                    break;
            }
        }
        visited[src] = false;
        return n_value;
    }

    vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values, vector<vector<string> > &queries)
    {
        int n = values.size(), m = queries.size();
        vector<double> ans(m);

        for (int i = 0; i < n; ++i)
        {
            string src = equations[i][0], dest = equations[i][1];
            double w = values[i];
            graph[src].push_back({dest, w});
            graph[dest].push_back({src, 1.0 / w});
            visited[src] = visited[dest] = false;
        }

        for (int i = 0; i < m; ++i)
        {
            string src = queries[i][0], dest = queries[i][1];
            for (auto &[x, y] : visited)
            {
                y = false;
            }
            ans[i] = dfs(src, dest, 1.0);
        }

        return ans;
    }
};