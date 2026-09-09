class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
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
                pair<int, int> topElement = q.front();
                q.pop();
                int row = topElement.first;
                int col = topElement.second;
                for (int k = 0; k < 4; k++) {
                    int nextRow = row + x[k];
                    int nextCol = col + y[k];
                    if (isValid(nextRow, nextCol, n, m) &&
                        grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 2;
                        freshCount--;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
        return freshCount > 0 ? -1 : min;
    }
};