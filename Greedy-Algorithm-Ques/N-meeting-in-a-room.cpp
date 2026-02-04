class Solution {
public:
static bool cmp(pair<int,int> a, pair<int,int> b) {
return a.second < b.second;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if(n == 0) return 0;

    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({start[i], end[i]});
    }

    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int lastEnd = v[0].second;

    for(int i = 1; i < n; i++) {
        if(v[i].first > lastEnd) {
            count++;
            lastEnd = v[i].second;
        }
    }
    return count;
}
};
