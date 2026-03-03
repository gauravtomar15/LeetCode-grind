class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = INT_MIN; 
        int res  = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevNoDelete = noDelete;
            int prevOneDelete = oneDelete;

            noDelete = max(prevNoDelete + arr[i], arr[i]);

            int v1;
            if (prevOneDelete == INT_MIN) {
                v1 = arr[i];
            } else {
                v1 = prevOneDelete + arr[i];
            }
            oneDelete = max(v1, prevNoDelete);
            res = max(res, max(oneDelete, noDelete));
        }
        return res;
    }
};