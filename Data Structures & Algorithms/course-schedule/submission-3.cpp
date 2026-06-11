#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(vector<int>& visited, vector<int>& resStack, 
             unordered_map<int, vector<int>>& preMap, int index) {
        
        // the current course has no prerequisite
        if (!preMap.count(index) || preMap[index].empty()){
            visited[index] = true;
            return true;
        }

        resStack[index] = true;

        vector<int> prqs = preMap[index];
        for(auto& p : prqs){
            if (resStack[p]){
                return false;
            }
            if (!dfs(visited, resStack, preMap, p)){
                return false;
            }
        }

        resStack[index] = false;
        visited[index] = true;

        preMap[index].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // convert prerequisites into an unordered map
        unordered_map<int, vector<int>> preMap;
        for(auto& p : prerequisites) {
            preMap[p[0]].push_back(p[1]);
        }

        vector<int> visited(numCourses, 0); // courses which are identified as no circular relations
        vector<int> resStack(numCourses, 0); // temporarily store whether the recursion call of a course is called or not

        for (int i = 0; i < numCourses; i++) {
            // call dfs for current course if it's not visited before
            if (!visited[i]) {
                if (!dfs(visited, resStack, preMap, i)){
                    return false;
                }
            }
        }
        return true;
    }
};