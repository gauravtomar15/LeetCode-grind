class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int res = 0;
        int maxCount = 0;
        
        for (high = 0; high < nums.size(); high++) {
            if(nums[high]==0){
                maxCount++;
            }
            while(maxCount>k){
                if(nums[low]==0){
                    maxCount--;
                }
                low++;
            }
           
            int length = high - low + 1;
            res = max(res, length);
        }
        return res;
    }
};