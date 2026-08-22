class Solution {
public:
    void check(string digits, int n, int i, string dairy, vector<string>& res,
               unordered_map<char, string>& mp) {

        if (n == i) {
            res.push_back(dairy);
            return;
        }
        string choice = mp[digits[i]];
        for (int j = 0; j < choice.size(); j++) {
            dairy.push_back(choice[j]);
            check(digits, n, i + 1, dairy, res, mp);
            dairy.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        int n = digits.size();
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> res;
        check(digits, n, 0, "", res, mp);
        return res;
    }
};