class Solution {
public:
    int solveOne(vector<int>& nums) {
        int bestEnding = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            bestEnding = max(bestEnding + nums[i], nums[i]);
            res = max(res, bestEnding);
        }
        return abs(res);
    }
     int solevTwo(vector<int>& nums) {
        int bestEnding = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            bestEnding = min(bestEnding + nums[i], nums[i]);
            res = min(res, bestEnding);
        }
        return abs(res);
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = solveOne(nums);
        int min = solevTwo(nums);
        int res = max(maxi, min);
        return res;
    }
};