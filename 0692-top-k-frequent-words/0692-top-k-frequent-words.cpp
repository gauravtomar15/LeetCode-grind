class Solution {
public:
    using p = pair<int, string>;
    struct cmp {
        bool operator()(p& a, p& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first; // joo bhi return uskoo priorty dii jaigii
        }
    };
    vector<string> topKFrequent(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        priority_queue<p, vector<p>, cmp> pq;
        for (auto val : mp) {
            string element = val.first;
            int freq = val.second;
            if (pq.size() < k) {
                pq.push({freq, element});
            } else if (pq.top().first < freq) {
                pq.pop();
                pq.push({freq, element});
            } else if (pq.top().first == freq && pq.top().second > element) {
                pq.pop();
                pq.push({freq, element});
            }
        }
        vector<string> ans;

        while (pq.size() != 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

