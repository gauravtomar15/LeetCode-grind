class Solution {
public:
    int caluclateMaxiProfit(vector<int>& nums, int n, int i, int free,
                            vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][free] != -1) {
            return dp[i][free];
        }
        if (free == 0) {
            return dp[i][free] = caluclateMaxiProfit(nums, n, i + 1, 1, dp);
        }
        int choice1 = nums[i] + caluclateMaxiProfit(nums, n, i + 1, 0, dp);
        int choice2 = caluclateMaxiProfit(nums, n, i + 1, 1, dp);

        return dp[i][free] = max(choice1, choice2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            vector<int> t(2, -1);
            dp[i] = t;
        }
        return caluclateMaxiProfit(nums, n, 0, 1, dp);
    }
};