class Solution {
	public:
	bool func(vector<int> &arr, int n, int k, long long guess) {
		int j = 1;
		long long page = 0;
		for (int i = 0 ; i<n; i++) {
			if (page + arr[i] <= guess) {
				page = page + arr[i];
			} else {
				j++;
				page = arr[i];
				if (j>k) {
					return false;
				}
			}
		}
		return true;
	}
	int findPages(vector<int> &arr, int k) {
		int n = arr.size();
		if(n<k){
		    return -1;
		}
	    int low = 0;
		long long high = 0;
		for (int i = 0; i<n; i++) {
			low = max(low, arr[i]);
			high = high + arr[i];
		}
		int res = -1;
		while (low <= high) {
			long long mid = low + (high - low)/2;
			if (func(arr, n, k, mid)) {
				res = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return res;
	}
};
