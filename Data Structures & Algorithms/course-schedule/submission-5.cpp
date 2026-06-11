#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(vector<int>& checked, vector<int>& resStack, 
             unordered_map<int, vector<int>>& preMap, int index) {

        checked[index] = true; // mark the current course as valid since no cycle occurs

        // the current course has no prerequisite
        if (preMap[index].empty()){
            return true;
        }

        resStack[index] = true; // push current recursion call to the stack

        vector<int>& prqs = preMap[index];
        for(auto& p : prqs){
            if (resStack[p]){
                return false;
            }
            if (!dfs(checked, resStack, preMap, p)){
                return false;
            }
        }

        resStack[index] = false; // remove current recursion call from the stack

        // Once a node is confirmed safe, you remove its dependencies
        // allows future DFS calls become faster
        preMap[index].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // convert prerequisites into an unordered map
        unordered_map<int, vector<int>> preMap;
        for(auto& p : prerequisites) {
            preMap[p[0]].push_back(p[1]);
        }

        vector<int> checked(numCourses, 0); // courses which are identified as no circular relations
        vector<int> resStack(numCourses, 0); // temporarily store whether the recursion call of a course is called or not

        for (int i = 0; i < numCourses; i++) {
            // call dfs for current course if it's not checked before
            if (!checked[i]) {
                if (!dfs(checked, resStack, preMap, i)){
                    return false;
                }
            }
        }
        return true;
    }
};