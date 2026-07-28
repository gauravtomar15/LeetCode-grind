class Solution {
public:
    int solveMax(vector<int>& nums) {
        int result = nums[0];
        int bestEnding = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            bestEnding = max(bestEnding + nums[i], nums[i]);
            result = max(result, bestEnding);
        }
        return abs(result);
    }
    int solveMin(vector<int>& nums) {
        int result = nums[0];
        int bestEnding = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            bestEnding = min(bestEnding + nums[i], nums[i]);
            result = min(result, bestEnding);
        }
        return abs(result);
    }
    int maxAbsoluteSum(vector<int>& nums) {

        int maxi = solveMax(nums);
        int min = solveMin(nums);
        int res = max(maxi, min);
        return res;
    }
};