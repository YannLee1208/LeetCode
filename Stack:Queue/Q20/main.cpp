#include <stack>
#include "string"

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> stack;
        for (int i = 0 ; i < s.size(); i ++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push(s[i]);
            else{

                if ( stack.size() == 0)
                    return false;

                char c = stack.top();
                stack.pop();
                char match;
                if ( s[i] == '}')
                    match = '{';
                if ( s[i] == ']')
                    match = '[';
                if ( s[i] == ')')
                    match = '(';
                if ( match != c )
                    return false;
            }
        }

        if (!stack.empty())
            return false;


        return true;
    }
};