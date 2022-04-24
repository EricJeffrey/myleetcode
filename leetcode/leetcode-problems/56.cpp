#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        const int n = intervals.size();
        if (n <= 0)
            return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) -> bool { return a.start < b.start; });
        Interval last = intervals[0];
        for (int i = 1; i < n; i++) {
            const Interval tmpinterval = intervals[i];
            if (tmpinterval.start <= last.end) {
                last.end = max(tmpinterval.end, last.end);
            } else {
                res.push_back(last);
                last = tmpinterval;
            }
        }
        res.push_back(last);
        return res;
    }
};
int main(int argc, char const *argv[]) { return 0; }
