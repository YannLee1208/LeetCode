#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 1 || n <= 1)
            return 1;

        int dp[m][n];
        dp[0][0] = 1;

        for (int i = 1; i < m; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; ++i) {
            dp[0][i] = 1;
        }

        for (int level = 1; level < m; ++level) {
            for (int index = 1; index < n; ++index) {
                dp[level][index] = dp[level-1][index] + dp[level][index - 1];
            }
        }

        return dp[m-1][n-1];
    }
};
