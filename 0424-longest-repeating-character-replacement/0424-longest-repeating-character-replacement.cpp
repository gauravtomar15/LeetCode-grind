class Solution {
public:
    int solve(vector<int>& arr){
        int ans =0;
        for(int i =0; i<arr.size();i++){
            ans = max(ans, arr[i]); 
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        vector<int> arr(26);
        int low = 0;
        int high = 0;
        int res = -1;
        

        for (high = 0; high < s.size(); high++) {
            arr[s[high] - 'A']++;
            int len = high - low + 1;
            int maxCount = solve(arr);
            int diff = len - maxCount;

            while (diff > k) {
                arr[s[low]-'A']--;
                low++;
                len = high - low + 1;
                maxCount = solve(arr);
                diff = len - maxCount;
            }
        

           res = max(res, high - low + 1);
        }

        return res;
    }
};