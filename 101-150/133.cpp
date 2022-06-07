/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> visited;
    Node *dfs(Node *node)
    {
        if (!node)
            return nullptr;
        if (visited.count(node) > 0)
            return visited[node];
        Node *tmp = new Node(node->val);
        visited[node] = tmp;
        for (auto &i : node->neighbors)
        {
            tmp->neighbors.push_back(dfs(i));
        }
        return tmp;
    }

    Node *cloneGraph(Node *node)
    {
        return dfs(node);
    }
};