class Solution {

private: 
    void dfs(int idx, unordered_map<int , vector<int>>& graph, unordered_set<int>& visited){
        
        if (visited.count(idx)) return;
        visited.insert(idx);
        
        // iteratively call dfs for the current node
        for(auto& adjIdx : graph[idx]){
            dfs(adjIdx, graph, visited);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {

        // an unordered_map to store the edge's graph
        unordered_map<int, vector<int>> graph;
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            int u = (*it)[0], v = (*it)[1];
            graph[u].push_back(v);
            graph[v].push_back(u);  // add reverse edge since its a undirected graph 
        }

        // using set to track the node which have been visited
        unordered_set<int> visited;

        // the number of connected components
        int numComponents = 0;

        // traverse the nodes in the graph
        // when a node hasn't been visited before, execute dfs to mark its all adjacent nodes as visited
        // when a dfs has returned, increment numComponents by 1
        for(int i = 0; i < n; i++){
            if (visited.count(i)) continue;

            dfs(i, graph, visited);
            numComponents++;
        }
        return numComponents;
    }
};
