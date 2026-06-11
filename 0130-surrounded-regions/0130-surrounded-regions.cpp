class Solution {
public:
    bool isInsideGrid(int row, int col, int totalRows, int totalCols) {
        if (row < 0 || row >= totalRows || col < 0 || col >= totalCols) {
            return false;
        }
        return true;
    }

    int rowOffset[4] = {-1, 1, 0, 0};
    int colOffset[4] = {0, 0, -1, 1};

    void markConnectedRegion(vector<vector<char>>& board,
                             int totalRows,
                             int totalCols,
                             int row,
                             int col) {
        board[row][col] = '#';

        for (int direction = 0; direction < 4; direction++) {
            int nextRow = row + rowOffset[direction];
            int nextCol = col + colOffset[direction];

            if (isInsideGrid(nextRow, nextCol, totalRows, totalCols) &&
                board[nextRow][nextCol] == 'O') {
                markConnectedRegion(board, totalRows, totalCols,
                                    nextRow, nextCol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int totalRows = board.size();
        int totalCols = board[0].size();

        int row, col;

        for (col = 0; col < totalCols; col++) {
            if (board[0][col] == 'O')
                markConnectedRegion(board, totalRows, totalCols, 0, col);
        }

        for (col = 0; col < totalCols; col++) {
            if (board[totalRows - 1][col] == 'O')
                markConnectedRegion(board, totalRows, totalCols,
                                    totalRows - 1, col);
        }

        for (row = 0; row < totalRows; row++) {
            if (board[row][0] == 'O')
                markConnectedRegion(board, totalRows, totalCols, row, 0);
        }

        for (row = 0; row < totalRows; row++) {
            if (board[row][totalCols - 1] == 'O')
                markConnectedRegion(board, totalRows, totalCols,
                                    row, totalCols - 1);
        }

        for (row = 0; row < totalRows; row++) {
            for (col = 0; col < totalCols; col++) {
                if (board[row][col] == '#')
                    board[row][col] = 'O';
                else
                    board[row][col] = 'X';
            }
        }
    }
};