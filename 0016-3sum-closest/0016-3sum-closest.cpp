class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int max_diff = INT_MAX;
        int n = nums.size();
        int result_sum = 0;
        sort(nums.begin() , nums.end());
        for (int i = 0; i < n-2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if (diff < max_diff) {
                    max_diff = diff;
                    result_sum = sum;
                }
                if (sum == target) {
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result_sum;
    }
};