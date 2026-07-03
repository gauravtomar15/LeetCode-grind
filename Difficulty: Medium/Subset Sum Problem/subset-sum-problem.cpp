class Solution {
	public:
	bool solve(vector<int>& arr , int sum , int n , int i , vector<vector<int>> &dp){
	    if(i==n){
	        if(sum==0){
	            return true;
	        }
	        return false;
	    }
	    if(dp[i][sum]!=-1){
	        return dp[i][sum];
	    }
	    if(arr[i]>sum){
	        return dp[i][sum]= solve(arr,sum,n,i+1,dp);
	    }
	    int choice1 = solve(arr,sum-arr[i],n,i+1,dp);
	    int choice2 = solve(arr,sum,n,i+1,dp);
	    
	    return dp[i][sum] = choice1 || choice2;
	}
	bool isSubsetSum(vector<int>& arr, int sum) {
		// code here
		int n = arr.size();
		vector<vector<int>> dp(n + 1);
		for (int i = 0 ; i <= n; i++) {
			vector<int> temp(sum + 1, -1);
			dp[i] = temp;
		}
		return solve(arr,sum,n,0,dp);
	}
};
