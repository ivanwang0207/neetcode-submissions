class Solution {

private:
    bool dfs(unordered_map<int, vector<int>>& prepMap, 
             vector<bool>& recurStack,
             int i) {

        // if there are no prerequisite for the current course, return true
        if (prepMap[i].size() == 0) return 1;

        // if recurStack[i] is true, return false because a cycle is detected
        if (recurStack[i]) return 0;

        recurStack[i] = 1; // mark current elem in recursive stack as true

        for(auto& p : prepMap[i]) {
            if (!dfs(prepMap, recurStack, p)) return false;
        }

        recurStack[i] = 0;

        // remove the prerequisite in the current course 
        prepMap[i].clear();

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create an unordered map that stores the prerequisites corresponding to a course
        unordered_map<int, vector<int>> prepMap;
        for(auto& c : prerequisites) {
            prepMap[c[0]].push_back(c[1]);
        }

        // iterate through the courses and check if there's any cycle is detected
        vector<bool> recurStack(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if (prepMap[i].size() > 0){
                if (!dfs(prepMap, recurStack, i)) return false;
            }
        }
        return true;
    }
};
