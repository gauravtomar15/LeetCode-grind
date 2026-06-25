class Solution {
	public:
	int calculateMax(vector<int> &val, vector<int> &wt, int n, int i, int cap, vector<vector<int>> &dp) {
		if (i == n) {
			return 0;
		}
		if (dp[i][cap] != -1) {
			return dp[i][cap];
		}
		if (wt[i]>cap) {
			return dp[i][cap] = calculateMax(val, wt, n, i + 1, cap, dp);
		}
		int choiceYes = val[i]+ calculateMax(val, wt, n, i + 1, cap - wt[i], dp);
		int choiceNo = calculateMax(val, wt, n, i + 1, cap, dp);
		
		return dp[i][cap] = max(choiceYes, choiceNo);
		
	}
	int knapsack(int W, vector<int> &val, vector<int> &wt) {
	    int n = val.size();
		vector<vector<int>> dp(n);
		for (int i = 0 ; i<n ; i++) {
			vector<int> t(W+1, -1);
			dp[i] = t;
		}
		return calculateMax(val, wt, n, 0, W, dp);
	}
};
