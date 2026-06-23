class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int st2 = intervals[i][0];
            int en2 = intervals[i][1];
            if (end >= st2) {
                start = start;
                end = max(end, en2);
                continue;
            }
            result.push_back({start, end});
            start = st2;
            end = en2;
        }
        result.push_back({start, end});
        return result;
    }
};