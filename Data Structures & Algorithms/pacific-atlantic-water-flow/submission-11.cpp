class Solution {

private:

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void bfs(vector<vector<int>>& heights, int i, int j, set<pair<int, int>>& res) {
        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()) {
            auto& [ci, cj] = q.front();
            q.pop();
            res.insert({ci, cj});

            for(auto& [di, dj] : directions) {
                if (ci + di < heights.size() && ci + di >= 0 && 
                    cj + dj < heights[0].size() && cj + dj >= 0 && 
                    heights[ci + di][cj + dj] >= heights[ci][cj] &&
                    !res.count({ci + di, cj + dj})) {
                    q.push({ci + di, cj + dj});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int height = heights.size();
        int width = heights[0].size();

        set<pair<int, int>> pacSet;
        set<pair<int, int>> atlSet;

        // check the cells which can flow to Pacific
        for (int i = 0; i < height; i++) {
            if (i == 0) {
                for (int j = 0; j < width; j++) {
                    bfs(heights, i, j, pacSet);
                }
            } else {
                // bfs on j = 0 only
                bfs(heights, i, 0, pacSet);
            }
        }

        // check the cells which can flow to Atlantic
        for (int i = height - 1; i >= 0; i--) {
            if (i == height - 1) {
                for (int j = width - 1; j >= 0; j--) {
                    bfs(heights, i, j, atlSet);
                }
            } else {
                // bfs on j = width - 1 only
                bfs(heights, i, width - 1, atlSet);
            }
        }

        // check the intersect of pacSet and atlSet
        vector<vector<int>> result;
        for(auto& p : pacSet) {
            if (atlSet.find(p) != atlSet.end()){
                result.push_back({p.first, p.second});
            }
        }
        return result;
    }
};
