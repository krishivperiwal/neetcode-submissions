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
    Node* cloneGraph(Node* node) {
       unordered_map<int,Node *> vis;
       return dfs(node,vis); 
    }

    Node *dfs(Node* node,unordered_map<int,Node *>& vis){
        if(!node)return NULL;

        if(vis.count(node->val))return vis[node->val];

        Node *newN = new Node(node->val);
        vis[node->val] = newN;

        for(auto nei:node->neighbors){
            newN->neighbors.push_back(dfs(nei,vis));
        }

        return newN;
    }
};
