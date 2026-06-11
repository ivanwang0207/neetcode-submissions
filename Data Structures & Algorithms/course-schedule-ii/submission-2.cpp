class Solution {

private:
    bool dfs(unordered_map<int, vector<int>>& prepMap, 
             vector<bool>& visited, vector<bool>& recurVec, 
             int i, vector<int>& res) {

        if (recurVec[i]) return false; // cycle is detected
        if (visited[i]) return true;

        visited[i] = 1;
        recurVec[i] = 1;

        for(auto& p : prepMap[i]) {
            if (!dfs(prepMap, visited, recurVec, p, res)) return false;
        }

        recurVec[i] = 0;

        res.push_back(i);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // convert prerequisites to unordered map
        unordered_map<int, vector<int>> adj;
        for(auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        // use the recursive vector to store the courses that are
        // tracked by the current dfs path
        vector<bool> visited(numCourses, 0);
        vector<bool> recurVec(numCourses, 0);
        vector<int> res;

        for(int i = 0; i < numCourses; i++) {
            if (!visited[i]){
                if (!dfs(adj, visited, recurVec, i, res)) 
                    return vector<int>();
            }
        }
        return res;
    }
};
