class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > nums[nums.size() - 1]) { // part1
                if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    if (nums[0] > target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            } else { // right sorted part

                if (nums[mid] > target) {
                    high = mid - 1;
                } else {

                    if (target <= nums[high]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }

        return -1;
    }
};