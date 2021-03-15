#include<stack>
#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/')
                continue;

            string s;

            while ( i < path.size() && path[i] != '/' ) {
                s += path[i++];
            }

            i--;

            if (s == ".")
                continue;
            else if (s == "..")
                if (!stack.empty())
                    stack.pop();
                else
                    continue;
            else
                stack.push(s);
        }

        if (stack.empty())
            return "";

        string res;
        while (!stack.empty()){
            res = "/" + stack.top() + res;
            stack.pop();
        }

        return res;

    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
