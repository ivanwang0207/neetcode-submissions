class Solution {

private:
    bool dfs(unordered_map<int, vector<int>>& adj, 
             vector<int>& visited, vector<int>& recurStack, 
             int curIdx) {

        if (recurStack[curIdx]) return 0;
        if (visited[curIdx]) return 1;

        recurStack[curIdx] = 1;
        visited[curIdx] = 1;

        for(auto& n : adj[curIdx]) {
            if (!dfs(adj, visited, recurStack, n))
                return 0;
        }

        recurStack[curIdx] = 0;
        return 1;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> visited(numCourses, 0);
        vector<int> recurStack(numCourses, 0);

        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            adj[course].push_back(prereq);
        }

        for(int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if(!dfs(adj, visited, recurStack, i)) 
                    return 0;
            }
        }
        return 1;
    }
};
