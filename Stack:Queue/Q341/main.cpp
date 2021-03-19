#include <iostream>
#include "vector"
#include "queue"

using namespace std;

class NestedInteger {
     public:
         // Return true if this NestedInteger holds a single integer, rather than a nested list.
         bool isInteger() const;

         // Return the single integer that this NestedInteger holds, if it holds a single integer
         // The result is undefined if this NestedInteger holds a nested list*
         int getInteger() const;

         // Return the nested list that this NestedInteger holds, if it holds a nested list
         // The result is undefined if this NestedInteger holds a single integer
          const vector<NestedInteger> &getList() const;
    };
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
       help(nestedList);
    }

    int next() {
        if (!q.empty()){
            int res = q.front();
            q.pop();
            return res;
        }

        throw invalid_argument("q is empty");
    }

    bool hasNext() {
        return !q.empty();
    }

private:
    queue<int> q;

    void help(const vector<NestedInteger> &nestedList){
        if (nestedList.empty())
            return;

        for (auto & nest : nestedList){
            if (nest.isInteger())
                q.push(nest.getInteger());
            else{
                help(nest.getList());
            }
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
