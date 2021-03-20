#include <iostream>
#include "vector"
#include "queue"

using namespace std;

class Solution {
public:
    int numSquares(int n) {

        // 第一个代表数字，第二个代表走了几步
        queue< pair<int, int> > q;
        q.push(make_pair(n, 0));

        vector<bool> visited(n + 1, false);
        visited[n] = true;

        while (! q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 1 ;  ; ++i) {
                int a = num - i * i;
                if (a < 0)
                    break;
                if (a == 0)
                    return step + 1;

                if (! visited[num - i * i]) {
                    q.push(make_pair(a, step + 1));
                    visited[a] = true;
                }
            }
        }

        throw invalid_argument("No Solution");
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}