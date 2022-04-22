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

class Solution {
public:
    unordered_map<Node*, Node*> dict;
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        if(dict.find(node) != dict.end())
            return dict[node];
        Node* p =  new Node(node->val);
        dict[node] = p;
        for(auto i: node->neighbors){
            p->neighbors.push_back(cloneGraph(i));
        }
        return p;
    }
};



class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* dfs(Node* node){
        if(!node)
            return nullptr;
        if(visited.find(node) != visited.end())
            return visited[node];
        Node* root = new Node(node->val);
        visited[node] = root;
        for(auto i: node->neighbors){
            root->neighbors.push_back(dfs(i));
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};