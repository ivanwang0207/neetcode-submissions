class Solution {

private:
    bool dfs(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, 
             int index, int parent) {

        // add the current element to the visited set
        visited.insert(index);

        for (auto& elem : adj[index]) {
            // if the decendent is just equal to its parent, continue the process
            if (parent == elem) 
                continue;

            // if the decendent has been visited before, return false cuz there's a cycle is detected
            if (visited.find(elem) != visited.end())
                return false;

            if (!dfs(adj, visited, elem, index)) 
                return false;
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        // number of nodes = number of edges + 1
        if (n - 1 != edges.size()){
            return false;
        }
        
        // use an unordered map to store the adjecent table for nodes 
        unordered_map<int, vector<int>> adj;
        for(auto& p : edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]); // undirected graph
        }

        // create a unordered_set that stores the element that are seen before
        unordered_set<int> visited;

        // use dfs method to traverse the nodes in a tree
        for(int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                if (!dfs(adj, visited, i, -1)){
                    return false;
                }
            }
        }
        return true;
    }
};
