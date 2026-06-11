class Solution {
public:

    bool dfs(int course, unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, vector<int>& result) {
        // Mark the course as visited and add it to the recursion stack
        visited[course] = true;
        recStack[course] = true;

        // Traverse all prerequisites of the current course
        for (int prereq : adj[course]) {
            if (!visited[prereq]) {
                // If the prerequisite has not been visited, recurse
                if (dfs(prereq, adj, visited, recStack, result)) {
                    return true; // Cycle detected
                }
            } else if (visited[prereq] && recStack[prereq]) {
                // If the prerequisite is already in the recursion stack (is visited), a cycle is detected
                return true;
            } 
            // if its visited and the recStack is false
            // meaning the prereq is checked to be valid, no cycle detected from it
        }

        // Remove the course from the recursion stack
        recStack[course] = false;
        result.push_back(course);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        // Visited and recursion stack arrays
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        vector<int> result;

        // Check for cycles in each connected component
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack, result)) {
                    return vector<int>(); // If a cycle is detected, return empty vector
                }
            }
        }
        return result; // No cycles detected
    }
};