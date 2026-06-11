class Solution {

private:
    void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int index) {
        visited[index] = 1;
        for(auto& elem : adj[index]) {
            if (visited[elem]) continue;
            dfs(adj, visited, elem);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // use a unodered map to store the adjacement map
        unordered_map<int, vector<int>> adj;
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, 0);

        int count = 0;
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};
