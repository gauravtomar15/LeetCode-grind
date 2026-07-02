class Solution {
public:
    double solveFunc(double x, long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return solveFunc(1 / x, -n);
        }
        if (n % 2 == 0) {
            return solveFunc(x * x, n / 2);
        } else {
            return x * solveFunc(x * x, (n - 1) / 2);
        }
    }
    double myPow(double x, int n) { return solveFunc(x, (long)n); }
};