#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int course, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
        // Mark the course as visited and add it to the recursion stack
        visited[course] = true;
        recStack[course] = true;

        // Traverse all prerequisites of the current course
        for (int prereq : adj[course]) {
            if (!visited[prereq]) {
                // If the prerequisite has not been visited, recurse
                if (dfs(prereq, adj, visited, recStack)) {
                    return true; // Cycle detected
                }
            } else if (recStack[prereq]) {
                // If the prerequisite is already in the recursion stack, a cycle is detected
                return true;
            }
        }

        // Remove the course from the recursion stack
        recStack[course] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        // Visited and recursion stack arrays
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        // Check for cycles in each connected component
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack)) {
                    return false; // If a cycle is detected, return false
                }
            }
        }
        return true; // No cycles detected, return true
    }
};