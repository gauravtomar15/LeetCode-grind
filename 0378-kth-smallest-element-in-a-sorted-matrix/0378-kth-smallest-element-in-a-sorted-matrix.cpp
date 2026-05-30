class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        vector<int> res;

        int n = matrix.size();
        int m = matrix[0].size();

        // Store all elements into 1D vector
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                res.push_back(matrix[i][j]);
            }
        }

        // Sort the array
        sort(res.begin(), res.end());

        // kth smallest element
        return res[k - 1];
    }
};