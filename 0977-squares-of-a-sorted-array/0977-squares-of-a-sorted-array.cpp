class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;

        // do array bana liye separate
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                positive.push_back(nums[i]);
            } else {
                negative.push_back(nums[i]);
            }
        }
        // check krenge value kya hai neg ya pos
        if (positive.size() == 0) { // no positive
            for (int i = 0; i < negative.size(); i++) {
                negative[i] = negative[i] * negative[i];
            }
            reverse(negative.begin(), negative.end());
            return negative;
        }
        if (negative.size() == 0) { // no negative
            for (int i = 0; i < positive.size(); i++) {
                positive[i] = positive[i] * positive[i];
            }
            return positive;
        }
        // ab merge kr dene dono psoitive or negative array ko 2-pointer
        // approach se

        int i = 0, j = 0;
        int idx = 0;
        int x = positive.size();
        int y = negative.size();
        vector<int> result(x + y);

        for (int i = 0; i < y; i++) {
            negative[i] = negative[i] * negative[i];
        }
        reverse(negative.begin(), negative.end());

        for (int j = 0; j < x; j++) {
            positive[j] = positive[j] * positive[j];
        }

        while (i < y && j < x) {
            if (negative[i] <= positive[j]) {
                result[idx] = negative[i];
                idx++;
                i++;
            } else {
                result[idx] = positive[j];
                idx++;
                j++;
            }
        }
        while (i < y) {
            result[idx] = negative[i];
            idx++;
            i++;
        }
        while (j < x) {
            result[idx] = positive[j];
            idx++;
            j++;
        }
        return result;
    }
};