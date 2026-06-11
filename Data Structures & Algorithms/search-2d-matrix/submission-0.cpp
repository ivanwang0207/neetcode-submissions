class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int row_count = matrix.size();
        int col_count = matrix[0].size();
        int e = row_count * col_count -1;

        while(s <= e) {
            int mid = (s + e) / 2;
            int row = mid / col_count;
            int col = mid % col_count;

            if (matrix[row][col] == target) return 1;

            else if (target < matrix[row][col]){
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return 0;
    }
};