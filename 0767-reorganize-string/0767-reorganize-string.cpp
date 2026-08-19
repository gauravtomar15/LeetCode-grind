class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        using p = pair<int, char>;
        priority_queue<p> pq;
        for (auto i : mp) {
            pq.push({i.second, i.first});
        }
        int seat = 0;
        string res = "";
        while (!pq.empty()) {
            pair<int, char> p1 = pq.top();
            pq.pop();
            if (seat == 0 || res[seat - 1] != p1.second) {
                res.push_back(p1.second);
                seat++;
                p1.first--;
                if (p1.first > 0) {
                    pq.push(p1);
                }
            } else {
                if (pq.empty()) {
                    return "";
                }
                pair<int, char> p2 = pq.top();
                pq.pop();
                if (seat == 0 || res[seat - 1] != p2.second) {
                    res.push_back(p2.second);
                    seat++;
                    p2.first--;
                    if (p2.first > 0) {
                        pq.push(p2);
                    }
                    pq.push(p1);
                }
            }
        }
        return res;
    }
};