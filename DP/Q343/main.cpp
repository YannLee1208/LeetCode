
#include "vector"

using namespace std;

class Solution {
private:
    vector<int> memo;
    std::
    int breakInteger(int n){
        if (n == 1)
            return 1;

        if (memo[n] != -1)
            return memo[n];

        int res = -1;
        for (int i = 1; i <= n - 1; ++i) {
            // 一定要注意此处 因为breakInteger是必须分成两部分的
            res = max(res, max (i * breakInteger(n - i), i * (n - i)) );
        }

        memo[n] = res;
        return res;
    }

public:
    int integerBreak(int n) {
        memo = vector<int>(n + 1, -1);
        return breakInteger(n);
    }

    int integerBreak2(int n) {
        memo = vector<int>( n + 1, - 1);
        memo[0] = 0;
        memo[1] = 1;

        for (int i = 2 ; i <= n; ++i) {
            for (int j = 1; j <= i - 1 ; ++j) {
                memo[i] = max(memo[i], max(j * (i - j), j * memo[i - j]));
            }
        }

        return memo[n];
    }
};