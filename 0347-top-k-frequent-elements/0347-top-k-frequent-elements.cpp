class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for (auto val : mp) {
            int element = val.first;
            int freq = val.second;
            if (pq.size() < k) {
                pq.push({freq, element});
            } else if (pq.top().first < freq) {
                pq.pop();
                pq.push({freq, element});
            } else if (pq.top().first == freq && pq.top().second < element) {
                pq.pop();
                pq.push({freq, element});
            }
        }
        vector<int> ans;
        while (pq.size() != 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};