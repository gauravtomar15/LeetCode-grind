class Solution {
public:
    // tabulation with space optimization
    int fib(int n) {
        if(n<=1) return n;
        int prev = 1;
        int prevofPrev = 0;
        int ans;
        for (int i = 2; i <= n; i++) {
            ans = prev + prevofPrev;
            prevofPrev = prev;
            prev = ans;
        }
        return ans;
    }
};