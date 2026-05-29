class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid) {
        // [2,4,6,8,10]
        // C = 10
        int k = 1; // 4
        // c = 10

        int count = 0;
        for (int i = 0; i < weights.size(); i++) {
            if ((count + weights[i]) <= mid) {
                count = count + weights[i];
            } else {
                k++;
                count = weights[i];
            }
        }

        if (k > days) {
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int res = -1;
        int low = INT_MIN;
        for(auto &val : weights){
            low=max(val,low);
        }
        int high=0;
        for (int i = 0; i < n; i++) {
            high = high + weights[i];
        }
        while (high >= low) {
            int mid = (low + high) / 2;
            if (isPossible(weights, days, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};