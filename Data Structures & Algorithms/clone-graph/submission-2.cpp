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

    void dfs(Node* oldNode, Node* newNode, unordered_map<Node*, Node*>& map) {

        for(auto& adjNode : oldNode->neighbors){

            auto it = map.find(adjNode);

            // if the newadjNode is not iterated before
            // find the node in the unordered map 
            // if not found, create the new node of val
            if (it == map.end()){
                Node* newAdjNode = new Node(adjNode->val);
                newNode->neighbors.push_back(newAdjNode);
                map[adjNode] = newAdjNode;
                
                dfs(adjNode, newAdjNode, map);  

            } else { // if the newadjNode is iterated already
                Node* newAdjNode = map[adjNode];
                newNode->neighbors.push_back(newAdjNode);
            }
        }
    }

public:
    Node* cloneGraph(Node* node) {

        // case: empty graph
        if (!node) return nullptr;

        // case: only one node without neighbors
        if (node->neighbors.empty())
            return new Node(node->val);

        Node* cloneNode = new Node(node->val);
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[node] = cloneNode;

        dfs(node, cloneNode, nodeMap);   

        return cloneNode;
    }
};
