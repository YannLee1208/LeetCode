#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    vector<int> memo;

    int climbStairs2(int n) {


        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        int res = 0;
        if (memo[n] == 0) {
            res = climbStairs(n - 1) + climbStairs(n - 2);
            memo[n] = res;
        } else
            res = memo[n];

        return res;
    }

    int climbStairs3(int n){
        vector<int> m ( n + 1, -1);
        m[0] = 1;
        m[1] = 1;

        for (int i = 2  ; i <= n ; ++i) {
            m[i] = m[i-1] + m[i-2];
        }

        return m[n];
    }


};

