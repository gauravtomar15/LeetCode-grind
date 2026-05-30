class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  // Total number of rows
        int n = matrix[0].size();     // Total number of columns
        
        int row = 0;   // Start from first row
        int col = n - 1;     // Start from last column (top-right corner)
        
        // Continue until row and column remain inside matrix
        while (row < m && col >= 0) {
            // If current element equals target
            if (matrix[row][col] == target) {
                return true;
            }
            // If current element is greater than target
            // move left because all elements below are bigger
            else if (matrix[row][col] > target) {
                col--;
            }
            // If current element is smaller than target
            // move downward because all elements left are smaller
            else {
                row++;
            }
        }
        // Target not found
        return false;
    }
};