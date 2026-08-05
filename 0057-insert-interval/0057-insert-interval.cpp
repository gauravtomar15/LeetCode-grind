class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; }
    vector<vector<int>> merge(vector<vector<int>>& ans) {
        int n = ans.size();
        int s1 = ans[0][0];
        int e1 = ans[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < n; i++) {
            int s2 = ans[i][0];
            int e2 = ans[i][1];
            if (e1 >= s2) {
                s1 = s1;
                e1 = max(e1, e2);
                continue;
            }
            res.push_back({s1, e1});
            s1 = s2;
            e1 = e2;
        }
        res.push_back({s1, e1});
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        bool insertCheck = false;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (insertCheck == false && intervals[i][0] >= newInterval[0]) {
                ans.push_back(newInterval);
                insertCheck = true;
            }
            ans.push_back(intervals[i]);
        }
        if (insertCheck == false) {
            ans.push_back(newInterval);
        }
        sort(ans.begin(), ans.end(), cmp);
        return merge(ans);
    }
};