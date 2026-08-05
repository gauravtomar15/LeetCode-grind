class Solution {
	public:
	int minMeetingRooms(vector<int> &start, vector<int> &end) {
		// code here
		sort(start.begin(), start.end());
		sort(end.begin(), end.end());
		int room = 0;
		int ans = 0;
		int left = 0, right = 0;
		while (left<start.size()) {
			if (start[left]<end[right]) {
				room++;
				ans = max(ans, room);
				left++;
			} else {
				room--;
				ans = max(ans, room);
				right++;
			}
		}
		return ans;
	}
};
