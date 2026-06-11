class Solution {

private:
    bool binarySearch(const vector<vector<int>>& matrix, int lb, int rb, int target) {
        int mid = lb + (rb - lb) / 2;
        int r = mid / matrix[0].size();
        int c = mid - r * matrix[0].size();

        if (lb > rb) return false;
        if (matrix[r][c] == target) return true;

        if (matrix[r][c] < target) {
            return binarySearch(matrix, mid + 1, rb, target);
        } else {
            return binarySearch(matrix, lb, mid - 1, target);
        }
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row * col - 1;

        return binarySearch(matrix, left, right, target);
    }
};
