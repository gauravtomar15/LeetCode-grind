class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>arr;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int s = nums[i]*nums[i];
            arr.push_back(s);
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};