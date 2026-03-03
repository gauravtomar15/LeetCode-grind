class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int v1 = bestEnding + nums[i];
            int v2 = nums[i];
            bestEnding = max(v1, v2);
            result = max(result, bestEnding);
        }
        return result;
    }
};