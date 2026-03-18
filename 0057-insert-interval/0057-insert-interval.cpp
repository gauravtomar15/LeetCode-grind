class Solution {
    static bool sortCol(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& res) {
        int n = res.size();
        vector<vector<int>> res2;

        int start1 = res[0][0];
        int end1 = res[0][1];
        for (int i = 1; i < n; i++) {
            int start2 = res[i][0];
            int end2 = res[i][1];
            if (end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            res2.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        res2.push_back({start1, end1});
        return res2;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        bool add = false;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (add == false && intervals[i][0] >= newInterval[0]) {
                res.push_back(newInterval);
                add = true;
            }
            res.push_back(intervals[i]);
        }
        if (add == false) {
            res.push_back(newInterval);
        }

        sort(res.begin(), res.end(), sortCol);

        return merge(res);
    }
};