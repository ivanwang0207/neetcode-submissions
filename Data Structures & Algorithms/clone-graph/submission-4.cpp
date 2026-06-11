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

    Node* dfs(Node* srcNode, unordered_map<int, Node*>& nodeMap) {

        if (!srcNode) return nullptr; // empty graph

        int srcIdx = srcNode->val;
        Node* newNode = new Node(srcIdx);
        nodeMap.insert({srcIdx, newNode}); // add node index to the set

        // iterate the adjacent indices corresponding to the current node
        for(auto* adj : srcNode->neighbors) {

            if (nodeMap.count(adj->val))
                newNode->neighbors.emplace_back(nodeMap[adj->val]);

            else {
                Node* adjNode = dfs(adj, nodeMap);
                if (adjNode) {
                    newNode->neighbors.emplace_back(adjNode);
                }
            }
        }
        return newNode;
    }


public:
    Node* cloneGraph(Node* node) {
        
        // create an unordered_map to keep track of node's index and its pointer which has been created
        unordered_map<int, Node*> nodeMap;
        return dfs(node, nodeMap);
    }
};
