class Solution {
public:
    void check(int open, int close, string temp, int n, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(temp);
            return;
        }
        if (open < n) {
            temp.push_back('(');
            check(open + 1, close, temp, n, ans);
            temp.pop_back();
        }
        if (close < open) {
            temp.push_back(')');
            check(open, close + 1, temp, n, ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        check(0, 0, "", n, ans);
        return ans;
    }
};