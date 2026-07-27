class Solution {
	public:
	int longestKSubstr(string &s, int k) {
		// code here
		int n = s.size();
		unordered_map<int, int> mp;
		int res = INT_MIN;
		int low = 0, high = 0;
		for (high = 0 ; high<n; high++) {
			mp[s[high]]++;
			while (mp.size()>k) {
				mp[s[low]]--;
				if (mp[s[low]] == 0) {
					mp.erase(s[low]);
				}
				low++;
			}
			if (mp.size() == k) {
				int len = high - low + 1;
				res = max(res, len);
			}
		}
		if (mp.size() == 0 || mp.size()<k) {
			return - 1;
		}
		return res;
	}
};
