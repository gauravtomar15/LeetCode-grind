class Solution {
	public:
	bool func(vector<int> &arr, int n, int k, int guess) {
		int cows = 1;
		int pos = arr[0];
		for (int i = 1 ; i<n ; i++) {
			int dist = arr[i]-pos;
			if (dist<guess) {
				continue;
			}
			cows++;
			pos = arr[i];
		}
		if (cows >= k) {
			return true;
		} else {
			return false;
		}
	}
	int aggressiveCows(vector<int> &arr, int k) {
		
		int n = arr.size();
		int low = 1;
		sort(arr.begin(), arr.end());
		int high = arr[n - 1]-arr[0];
		int res = -1;
		while (low <= high) {
			int mid = low + (high - low)/2;
			if (func(arr, n, k, mid)) {
				res = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return res;
	}
};
