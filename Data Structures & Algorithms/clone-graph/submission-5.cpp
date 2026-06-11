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

private:
    Node* dfs(unordered_map<Node*, Node*>& created, Node* node) {
        if (created.count(node)) {
            return created[node];
        }

        Node* clone = new Node(node->val);
        created[node] = clone;

        for (Node* nei : node->neighbors) {
            clone->neighbors.push_back(dfs(created, nei));
        }

        return clone;
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        // create an unordered_map that tracks if a node has been created given its src Node
        unordered_map<Node*, Node*> created;

        // use DFS method
        return dfs(created, node);
    }
};
