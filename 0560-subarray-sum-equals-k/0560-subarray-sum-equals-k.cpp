class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0;

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            int ques = sum - k;
            int freq = mp[ques];
            res = res + freq;
            mp[sum]++;
        }
        return res;
    }
};