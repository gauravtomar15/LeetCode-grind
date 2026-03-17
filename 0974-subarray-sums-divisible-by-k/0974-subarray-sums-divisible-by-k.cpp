class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            int rem = sum % k;
            if (rem < 0) {
                rem = rem + k;
            }
            res = res + mp[rem];
            mp[rem]++;
        }
        return res;
    }
};