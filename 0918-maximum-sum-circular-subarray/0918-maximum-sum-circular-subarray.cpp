class Solution {
public:
    int solveMaximum(vector<int>& nums) {
        int bestEnding = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            bestEnding = max(bestEnding + nums[i], nums[i]);
            result = max(result, bestEnding);
        }
        return result;
    }
    int solveMinimum(vector<int>& nums) {
        int bestEnding = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            bestEnding = min(bestEnding + nums[i], nums[i]);
            result = min(result, bestEnding);
        }
        return result;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = solveMaximum(nums);
        int minimum = solveMinimum(nums);
        int total_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            total_sum = total_sum + nums[i];
        }
        if (maxi < 0) {
            return maxi;
        }
        int res = max(maxi, (total_sum - minimum));
        return res;
    }
};