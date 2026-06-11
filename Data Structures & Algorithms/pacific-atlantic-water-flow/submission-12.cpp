class Solution {

using coor2d = pair<bool, bool>;

enum Ocean {
    PACIFIC,
    ATLANTIC
};

private:

    void DFS(const vector<vector<int>>& heights, 
             std::vector<std::vector<coor2d>>& flowElems,
             int i, int j, Ocean ocean) {

        int H = heights.size();
        int W = heights[0].size();

        switch (ocean)
        {
            case Ocean::PACIFIC:
                flowElems[i][j].first = 1;
                break;
            case Ocean::ATLANTIC:
                flowElems[i][j].second = 1;
                break;
        }

        const static double directions[4][2] = 
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && 
                heights[ni][nj] >= heights[i][j]) {

                bool nextStatus = 0;
                if (ocean == Ocean::PACIFIC) {
                    nextStatus = flowElems[ni][nj].first;
                } else {
                    nextStatus = flowElems[ni][nj].second;
                }
                if (!nextStatus)
                    DFS(heights, flowElems, ni, nj, ocean);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int H = heights.size();
        int W = heights[0].size();

        std::vector<std::vector<coor2d>> flowElems(
            H, std::vector<coor2d>(W, {0, 0}));

        // do DFS on Pacific: start from row 0 and col 0
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                if (i != 0 && j != 0) continue;
                DFS(heights, flowElems, i, j, Ocean::PACIFIC);
            }
        }

        // do DFS on Atlantic: start from last row and last col
        for(int i = H - 1; i >= 0; --i) {
            for(int j = W - 1; j >= 0; --j) {
                if (i != H - 1 && j != W - 1) continue;
                DFS(heights, flowElems, i, j, Ocean::ATLANTIC);
            }
        }

        // extract the cells which are both flowable toward pacific and altlantic
        std::vector<std::vector<int>> res;
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                const auto [fi, fj] = flowElems[i][j];
                if (fi == 1 && fj == 1) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
