class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        int res = INT_MAX;
        unordered_map<char, int> have;
        unordered_map<char, int> need;
        string s = "balloon";
        for (int i = 0; i < s.size(); i++) {
            need[s[i]]++;
        }
        for (int i = 0; i < n; i++) {
            have[text[i]]++;
        }
        for (auto i : need) {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            int times = fhave/fneed;
            res = min(res, times);
        }
        return res;
    }
};