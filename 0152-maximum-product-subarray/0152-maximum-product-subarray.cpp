class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minbestEnding = nums[0];
        int maxbestEnding = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int v1 = minbestEnding * nums[i];
            int v2 = maxbestEnding * nums[i];
            int v3 = nums[i];
            maxbestEnding = max(v1, max(v2,v3));
            minbestEnding = min(v1, min(v2,v3));
            result = max(result, max(maxbestEnding , minbestEnding));
        }
        return result;
    }
};