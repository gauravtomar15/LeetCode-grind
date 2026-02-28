class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(256);
        int low = 0;
        int high = 0;
        int res = INT_MIN;
        for (high = 0; high < s.size(); high++) {
            arr[s[high]]++;
            int len = high - low + 1;
            int maxCount = max(maxCount, arr[s[high]]);
            int diff = len - maxCount;
            while (diff > k) {
                arr[s[low]]--;
                low++;
                len = high - low + 1;
                maxCount = max(maxCount, arr[s[high]]);
                diff = len - maxCount;
            }
            len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};