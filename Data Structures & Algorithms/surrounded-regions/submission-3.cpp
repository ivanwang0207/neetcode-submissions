class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // create a safe board to record if the 'O' is secured
        vector<vector<bool>> safe(rows, vector<bool>(cols, 0));

        // padding the border and all X as safe
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if (board[i][j] == 'X'){
                    safe[i][j] = 1;
                }
                else if (board[i][j] == 'O' && 
                    (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)){
                    dfs(board, safe, i, j); // will be primarily set as safe
                }
            }
        }

        // flip the O as X if its marked as unsafe
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if (safe[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& safe, int m, int n) {
        // also check if the current cell is safe or not 
        if (m < 0 || m >= board.size() || n < 0 || 
            n >= board[0].size() || board[m][n] != 'O'|| safe[m][n]) {
            return;
        }

        // cell == 'O' && currently unsafe
        safe[m][n] = 1; 

        dfs(board, safe, m + 1, n);
        dfs(board, safe, m - 1, n);
        dfs(board, safe, m, n + 1);
        dfs(board, safe, m, n - 1);
    }

};
