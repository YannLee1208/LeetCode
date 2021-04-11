#include <iostream>
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s == "0")
            return 0;

        int n = s.size();

        if (n == 1)
            return 1;

        vector<int> dp(s.size() +1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int n1= s[i-1]-'0';
            int n2= (s[i-2]-'0')*10 + (s[i-1]-'0');
            if(n1>0){
                dp[i]+= dp[i-1];
            }
            if(n2>9 && n2<27){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
