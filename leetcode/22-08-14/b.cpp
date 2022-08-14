#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int> &edges) {
        vector<long long> nodesScore(edges.size(), 0);
        for (size_t i = 0; i < edges.size(); i++) {
            nodesScore[edges[i]] += i;
        }
        long long maxVal = nodesScore[0];
        int res = 0;
        for (size_t i = 0; i < nodesScore.size(); i++) {
            if (nodesScore[i] > maxVal) {
                maxVal = nodesScore[i];
                res = i;
            }
        }
        return res;
    }
};