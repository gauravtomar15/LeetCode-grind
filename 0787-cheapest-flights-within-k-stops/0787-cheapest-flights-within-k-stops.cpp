class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> res(n, 1e8);
        res[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = res;
            for (int j = 0; j < flights.size(); j++) {
                int source = flights[j][0];
                int dist = flights[j][1];
                int weight = flights[j][2];

                if (res[source] != 1e8 && temp[dist] > (res[source] + weight)) {
                    temp[dist] = res[source] + weight;
                }
            }
            res = temp;
        }
        if (res[dst] == 1e8) {
            return -1;
        }
        return res[dst];
    }
};