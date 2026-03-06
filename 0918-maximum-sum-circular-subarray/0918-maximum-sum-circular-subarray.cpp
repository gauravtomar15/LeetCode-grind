class Solution {
public:
    int maxKadane(vector<int>& nums) {
        int bestEnding = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            bestEnding = max(bestEnding + nums[i], nums[i]);
            res = max(res, bestEnding);
        }
        return res;
    }
    int minKadane(vector<int>& nums) {
        int bestEnding = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            bestEnding = min(bestEnding + nums[i], nums[i]);
            res = min(res, bestEnding);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int v1 = maxKadane(nums);
        int v2 = minKadane(nums);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }
        if(v1<0){
            return v1;
        }
        int result = max(sum - v2, v1);
        return result;
    }
};