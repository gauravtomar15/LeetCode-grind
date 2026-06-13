class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            vector<int> temp(m, INT_MAX);
            res[i] = temp;
        }
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        res[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int dist = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if (dist > res[row][col]) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int newRow = row + x[k];
                int newCol = col + y[k];
                if (!valid(newRow, newCol, n, m)) {
                    continue;
                }
                int absDiff = abs(heights[row][col] - heights[newRow][newCol]);
                int newWeight = max(absDiff, dist);
                if (newWeight < res[newRow][newCol]) {
                    res[newRow][newCol] = newWeight;
                    pq.push({newWeight, {newRow, newCol}});
                }
            }
        }
        return res[n - 1][m - 1];
    }
};