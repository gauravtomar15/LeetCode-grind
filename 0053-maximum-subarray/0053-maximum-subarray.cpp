class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int bestEnding = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int choice1 = nums[i];
            int choice2 = bestEnding + choice1;
            bestEnding = max(choice1, choice2);
            result = max(result, bestEnding);
        }
        return result;
    }
};