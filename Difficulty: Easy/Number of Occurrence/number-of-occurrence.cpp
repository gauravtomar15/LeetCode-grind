class Solution {
	public:
	int firstOcc(vector<int>& nums, int target) {
		int n = nums.size();
		int low = 0;
		int high = n - 1;
		int res = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] > target) {
				high = mid - 1;
			} else if (nums[mid] < target) {
				low = mid + 1;
			} else {
				res = mid;
				high = mid - 1;
			}
		}
		return res;
	}
	int secondOcc(vector<int>& nums, int target) {
		int n = nums.size();
		int low = 0;
		int high = n - 1;
		int res = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] > target) {
				high = mid - 1;
			} else if (nums[mid] < target) {
				low = mid + 1;
			} else {
				res = mid;
				low = mid + 1;
			}
		}
		return res;
	}
	int countFreq(vector<int>& nums, int target) {
		int ans1 = firstOcc(nums, target);
		if(ans1==-1){
		    return 0;
		}
		int ans2 = secondOcc(nums, target);
		
		int diff = ans2-ans1;
		return diff+1;
		
	}
};
