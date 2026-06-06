class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        int sum =0;
        for(int i =0;i<n-1;i++){
            sum = sum + nums[i];
            leftSum[i+1] =sum;
        }
        int sumR = 0;
         for(int i =n-2;i>=0;i--){
            sumR = sumR + nums[i];
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};