class Solution {
    static bool sortCol(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), sortCol);
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if (end1 >= start2) { // merge krna ha
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        res.push_back({start1, end1});
        return res;
    }
};