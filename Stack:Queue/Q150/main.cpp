#include <iostream>
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for (auto & c: tokens) {
            if (c == "*" || c == "+" || c == "-" || c == "/"){
                int n2 = stack.top();
                stack.pop();
                int n1 = stack.top();
                stack.pop();

                int sum;
                if (c == "*")
                    sum = n1 * n2;

                if (c == "+")
                    sum = n1 + n2;

                if (c == "-")
                    sum = n1 - n2;

                if (c == "/")
                    sum = n1 / n2;

                stack.push(sum);
            } else
                stack.push(stoi(c));
        }

        return stack.top();
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
