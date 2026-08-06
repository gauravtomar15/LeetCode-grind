class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        int n = s.size();
        vector<char> res(n);
        for (int i = 0; i < n; i++) {
            st.push(s[i]);
        }
        for (int i = 0; i < n; i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};