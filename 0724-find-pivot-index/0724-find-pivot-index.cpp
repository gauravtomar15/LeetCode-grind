class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {

            right = sum - nums[i] - left;
            if (left == right) {
                return i;
            }
            left = left + nums[i];
        }

        return -1;
    }
};