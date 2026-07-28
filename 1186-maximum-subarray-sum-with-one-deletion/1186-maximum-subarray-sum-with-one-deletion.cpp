class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int bestEndingNoDelete = arr[0];
        int bestEndingOneDelete = 0;
        int result = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevNoDelete = bestEndingNoDelete;
            int prevOneDelete = bestEndingOneDelete;
            bestEndingNoDelete = max(prevNoDelete + arr[i], arr[i]);
            bestEndingOneDelete = max(prevOneDelete + arr[i], prevNoDelete);

            result = max(result, max(bestEndingNoDelete, bestEndingOneDelete));
        }
        return result;
    }
};