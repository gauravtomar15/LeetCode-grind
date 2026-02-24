class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int target_idx = -1;

        // target index find karenge pehle
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                target_idx = i - 1;
                break;
            }
        }

        // swap krne ke liye index dhundnge kha se krna ha h swap
        if (target_idx != -1) {
            int swap_idx = target_idx;
            for (int j = n - 1; j >= target_idx + 1; j--) {
                if (nums[target_idx] < nums[j]) {
                    swap_idx = j;
                    break;
                }
            }
            swap(nums[target_idx], nums[swap_idx]);
        }
        reverse(nums.begin() + target_idx + 1, nums.end());
    }
};