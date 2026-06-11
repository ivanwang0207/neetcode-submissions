class Solution {
public:
    // int helper(int n) {
    //     if (n == 0) return 0;
    //     if (n == 1) return 1;
    //     if (n == 2) return 2;

    //     return helper(n - 2) + helper(n - 1);
    // }

    int helper(int n) {
        int n_1 = 1;
        int n_2 = 2;
        if (n < 3) return n;
        for (int i = 3; i <= n; i++){
            int tmp = n_2;
            n_2 += n_1;
            n_1 = tmp;
        }
        return n_2;
    }

    int climbStairs(int n) {
        return helper(n);
    }
};
