class Solution {

private:
    void dfs(vector<vector<int>>& heights, set<pair<int, int>>& hashSet, 
             int i, int j) {
        
        // define the directions for current cell
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int h = heights.size();
        int w = heights[0].size();

        for(auto& d : directions) {
            int new_i = i + d.first;
            int new_j = j + d.second;

            if (new_i < 0 || new_i >= h ||
                new_j < 0 || new_j >= w ||
                heights[new_i][new_j] < heights[i][j] ||
                hashSet.count({new_i, new_j})){
                continue;
            }

            hashSet.insert({new_i, new_j});
            dfs(heights, hashSet, new_i, new_j);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int h = heights.size();
        int w = heights[0].size();

        // use hashset to store the cells which can flow to the Pacific
        set<pair<int, int>> to_pacific;
        set<pair<int, int>> to_atlantic;

        int i, j;
        // check cells which can flow to the Pacific
        // left
        i = 0;
        for(j = 0; j < w; j++) {
            to_pacific.insert({i, j});
            dfs(heights, to_pacific, i, j);
        }
        // up
        j = 0;
        for(i = 0; i < h; i++) {
            to_pacific.insert({i, j});
            dfs(heights, to_pacific, i, j);
        }

        // check cells which can flow to the atlantic
        // right
        i = h - 1;
        for(j = 0; j < w; j++) {
            to_atlantic.insert({i, j});
            dfs(heights, to_atlantic, i, j);
        }
        // down
        j = w - 1;
        for(i = 0; i < h; i++) {
            to_atlantic.insert({i, j});
            dfs(heights, to_atlantic, i, j);
        }

        // the union of to_pacific, to_atlantic
        vector<vector<int>> result;
        for (auto& e : to_atlantic) {
            if (to_pacific.count(e)) { 
                result.push_back({e.first, e.second}); 
            }
        }
        return result;
    }
};