class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if (end >= start2) {
                start = start;
                end = max(end, end2);
                continue;
            }
            result.push_back({start, end});
            start = start2;
            end = end2;
        }
        result.push_back({start, end});
        return result;
    }
};