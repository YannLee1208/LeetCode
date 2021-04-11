#include <iostream>
#include "vector"

using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1)
            return triangle[0][0];

        int n = triangle.size();
        vector<vector<int> > dp;
        int min_sum = INT_MAX;

        for (int i = 0; i < n; ++i) {
            dp.emplace_back(triangle[i].size(), 0);
        }

        dp[0][0] = triangle[0][0];
        for (int level = 1; level < n; ++level){
            int level_size = dp[level].size();
            for (int level_index = 0; level_index < level_size; ++level_index) {
                if (level_index == 0)
                    dp[level][level_index] = dp[level-1][0] + triangle[level][0];
                else if (level_index == level_size - 1)
                    dp[level][level_index] = dp[level-1][level_index-1] + triangle[level][level_index];
                else
                    dp[level][level_index] = min(dp[level-1][level_index-1] , dp[level-1][level_index]) + triangle[level][level_index];

                if (level == n - 1)
                    min_sum = min(min_sum, dp[level][level_index]);
            }
        }

        return min_sum;


    }
};
