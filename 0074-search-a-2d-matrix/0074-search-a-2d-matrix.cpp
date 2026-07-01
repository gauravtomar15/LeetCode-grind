class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row * col - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int newRow = mid / col;
            int newCol = mid % col;
            if (matrix[newRow][newCol] > target) {
                end = mid - 1;
            } else if (matrix[newRow][newCol] < target) {
                start = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};