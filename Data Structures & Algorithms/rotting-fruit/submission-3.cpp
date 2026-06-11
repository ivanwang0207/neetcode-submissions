class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> init_rotten;
        int fresh_count = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2)
                    init_rotten.push_back({i, j});
                // count total fresh in the grid
                else if (grid[i][j] == 1)
                    fresh_count++;
            }
        }
        if (fresh_count == 0) return 0;
        
        if (!init_rotten.empty()){
            int time = bfs(grid, init_rotten, fresh_count);
            return time;
        } else {
            return -1;
        }
    }

    int bfs(vector<vector<int>>& grid, vector<pair<int, int>>& init_rotten, int& fresh_count){
        int rows = grid.size();
        int cols = grid[0].size();
        int rotten_layer = 0;

        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = 
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto& ir : init_rotten){
            q.push(ir);
            grid[ir.first][ir.second] = 2; // for sure is rotten
        }

        while(!q.empty()){
            int size = q.size();
            int b_has_rotten = 0;

            // 每一層（layer）代表一個時間單位（minute）
            // 使用 for (int i = 0; i < size; i++) 
            // 是為了處理當前層的所有節點（rotting oranges）
            // 確保只有當前層的橘子處理完後，時間才會增加。
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                q.pop();

                for(const auto& d : directions){
                    int new_m = p.first + d.first;
                    int new_n = p.second + d.second;

                    if (new_m >= 0 && new_m < rows && 
                        new_n >= 0 && new_n < cols && 
                        grid[new_m][new_n] == 1){

                            q.push({new_m, new_n});
                            grid[new_m][new_n] = 2;
                            b_has_rotten = 1;
                            fresh_count--; // reduce fresh by 1
                    }
                }
            }
            if (b_has_rotten) rotten_layer++;
        }
        return fresh_count == 0 ? rotten_layer : -1;
    }
};
