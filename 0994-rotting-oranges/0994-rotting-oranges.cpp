class Solution {
public:
    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    bool isValidCell(int row, int col, int rows, int cols) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int freshCount = 0;
        int minutes = 0;

        queue<pair<int, int>> rottenQueue;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (grid[row][col] == 2) {
                    rottenQueue.push({row, col});
                } else if (grid[row][col] == 1) {
                    freshCount++;
                }
            }
        }

        while (!rottenQueue.empty() && freshCount > 0) {

            int currentLevelSize = rottenQueue.size();
            minutes++;

            while (currentLevelSize--) {

                auto currentCell = rottenQueue.front();
                rottenQueue.pop();

                int currentRow = currentCell.first;
                int currentCol = currentCell.second;

                for (int dir = 0; dir < 4; dir++) {

                    int nextRow = currentRow + rowDir[dir];
                    int nextCol = currentCol + colDir[dir];

                    if (isValidCell(nextRow, nextCol, rows, cols) &&
                        grid[nextRow][nextCol] == 1) {

                        grid[nextRow][nextCol] = 2;
                        freshCount--;

                        rottenQueue.push({nextRow, nextCol});
                    }
                }
            }
        }

        return freshCount > 0 ? -1 : minutes;
    }
};