class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                negative.push_back(nums[i]);
            } else {
                positive.push_back(nums[i]);
            }
        }
        if (negative.size() == 0) {
            for (int i = 0; i < positive.size(); i++) {
                positive[i] = positive[i] * positive[i];
            }
            return positive;
        }
        if (positive.size() == 0) {
            for (int i = 0; i < negative.size(); i++) {
                negative[i] = negative[i] * negative[i];
            }
            reverse(negative.begin(), negative.end());
            return negative;
        }

        int i = 0, j = 0;
        int idx = 0;
        int x = positive.size();
        int y = negative.size();
        // vector<int> result(x + y);

        for (int i = 0; i < negative.size(); i++) {
            negative[i] = negative[i] * negative[i];
        }
        reverse(negative.begin(), negative.end());
        for (int i = 0; i < positive.size(); i++) {
            positive[i] = positive[i] * positive[i];
        }
        while (i < x && j < y) {
            if (negative[j] <= positive[i]) {
                nums[idx] = negative[j];
                idx++;
                j++;
            } else {
                nums[idx] = positive[i];
                idx++;
                i++;
            }
        }
        while (i < x) {
            nums[idx] = positive[i];
            idx++;
            i++;
        }
        while (j < y) {
            nums[idx] = negative[j];
            idx++;
            j++;
        }
        return nums;
    }
};