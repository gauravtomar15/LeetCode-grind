class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool isValid(int n, int m, int nextRow, int nextCol) {
        if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m) {
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshCount = 0;
        int min = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        while (!q.empty() && freshCount > 0) {
            int levelSize = q.size();
            min++;
            while (levelSize--) {
                pair<int, int> currentCell = q.front();
                q.pop();
                int currentRow = currentCell.first;
                int currentCol = currentCell.second;
                for (int k = 0; k < 4; k++) {
                    int nextRow = currentRow + x[k];
                    int nextCol = currentCol + y[k];

                    if (isValid(n, m, nextRow, nextCol) &&
                        grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 2;
                        freshCount--;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
        return freshCount>0 ? -1 : min;
    }
};