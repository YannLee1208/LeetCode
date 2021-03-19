#include <iostream>
#include <vector>
#include <unordered_map>
#include "queue"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int,int> record;
//        vector<pair<int,int>> v;
//        vector<int> res;
//
//        for (auto i : nums) record[i] ++;
//        for (auto j : record) v.emplace_back(j);
//        sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b){ return a.second > b.second;});
//        for (int l = 0; l < k; ++l) {
//            res.push_back(v[l].first);
//        }
//        return res;

        unordered_map<int, int> freq;
        for (int & num : nums) {
            freq[num] ++;
        }

        // 频率，元素
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto & iter : freq){

            if (pq.size() == k) {
                if (iter.second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(iter.second, iter.first));
                }
            } else
                pq.push(make_pair(iter.second, iter.first));
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};