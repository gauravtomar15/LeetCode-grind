class Solution {
public:
    long long func(vector<int>& arr, int n, int speed) {
        long long h = 0;
        for (int i = 0; i < n; i++) {
            h = h + arr[i] / speed;
            if (arr[i] % speed != 0) {
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        int low = 1;
        int high = maxi;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long hours = func(piles, n, mid);
            if (hours > h) {
                low = mid + 1;
            } else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};