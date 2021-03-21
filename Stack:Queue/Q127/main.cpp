#include <iostream>
#include "vector"
#include "string"
#include "unordered_set"
#include "unordered_map"
#include "queue"

using namespace std;

class Solution {
public:
    int ladderLength(string& beginWord, string& endWord, vector<string>& wordList) {
        unordered_set<string> word(begin(wordList), end(wordList));
        if (word.find(endWord) == word.end())
            return 0;

        // graph
        unordered_map<string, vector<string>> map;
        wordList.push_back(beginWord);

        for (string& w : wordList){
            string orignal_word = w;
            for (int i = 0; i < w.size(); ++i) {
                char c = w[i];
                w[i] = '*';
                map[orignal_word].push_back(w);
                map[w].push_back(orignal_word);
                w[i] = c;
            }
        }

        // BFS
        unordered_set<string> visited;
        queue<pair<string,int> > queue;

        queue.push(make_pair(beginWord, 0));
        visited.insert(beginWord);

        while (!queue.empty()){
            string w = queue.front().first;
            int step = queue.front().second;
            queue.pop();

            if (w == endWord)
                return step / 2 + 1;

            for (string & neighbour : map[w]){
                if (visited.find(neighbour) == visited.end()){
                    visited.insert(neighbour);
                    queue.push(make_pair(neighbour, step + 1));
                }
            }
        }

        return 0;


    }
};

int main(){
    string begin = "hit";
    string end = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};


    Solution().ladderLength(begin, end,wordList);
};
