class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        bool odd = false;
        int res =0;
        for (auto i : mp) {
            int val = i.second;
            if (val % 2 == 0) {
                res = res + val;
            } else {
                odd = true;
            }
        }
        if (odd == false) {
            return res;
        }
        for (auto i : mp) {
            int val = i.second;
            if (val % 2 == 1) {
                res = res + val - 1;
            }
        }
        return res + 1;
    }
};