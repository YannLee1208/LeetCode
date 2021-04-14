#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector <vector<int>> &obs) {
        int m = obs.size();
        int n = obs[0].size();

        if ( m == 0 || n == 0)
            return 0;

        if (obs[0][0] == 1 || obs[m - 1][n - 1] == 1)
            return 0;

        int dp[m][n];
        dp[0][0] = 1;

        for (int i = 1; i < m; ++i) {
            if (obs[i][0])
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i-1][0];
        }

        for (int i = 1; i < n; ++i) {
            if (obs[0][i])
                dp[0][i] = 0;
            else
                dp[0][i] = dp[0][i-1];
        }

        for (int level = 1; level < m; ++level) {
            for (int index = 1; index < n; ++index) {
                if (obs[level][index])
                    dp[level][index] = 0;

                else
                    dp[level][index] = dp[level-1][index] + dp[level][index-1];
            }
        }

        return dp[m-1][n-1];

    }
};

int main(){

}