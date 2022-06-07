class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();

        vector<bool> visited(n, false);
        stack<int> s;
        s.push(start);
        while (!s.empty())
        {
            auto i = s.top();
            s.pop();
            visited[i] = true;
            if (arr[i] == 0)
                return true;
            if (i + arr[i] < n && !visited[i + arr[i]])
            {
                s.push(i + arr[i]);
            }
            if (i - arr[i] >= 0 && !visited[i - arr[i]])
            {
                s.push(i - arr[i]);
            }
        }

        return false;
    }
};