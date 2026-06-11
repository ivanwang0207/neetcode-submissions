class Solution {

private:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<int>& visited, int prevIdx, int currIdx){

        visited[currIdx] = true;

        vector<int>& adjIdxs = adj[currIdx];
        for(auto& adjIdx : adjIdxs) {
            if (visited[adjIdx]) {
                if (adjIdx == prevIdx) 
                    continue;
                return false;
            }
            if (!dfs(adj, visited, currIdx, adjIdx))
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

        unordered_map<int, vector<int>> adj;
        for(auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        // call dfs in order to check if the adjacent node forms a cycle with the previous visited nodes
        vector<int> visited(n, 0);
        dfs(adj, visited, -1, 0);

        auto begin = visited.begin();
        while(begin != visited.end()){
            if (!(*begin)) return false;
            begin++;
        }
        return true;
    }
};
