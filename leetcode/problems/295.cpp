#include <algorithm>
#include <array>
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
#include <vector>
using namespace std;

class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        const size_t n = data.size();
        data.insert(num);
        if (n == 0) {
            mid = data.begin();
        } else {
            if (num == *mid)
                mid = n & 1 ? mid : next(mid);
            else if (num < *mid)
                mid = n & 1 ? prev(mid) : mid;
            else
                mid = n & 1 ? mid : next(mid);
        }
    }

    double findMedian() { return data.size() & 1 ? *mid : ((*mid) + (double)(*next(mid))) * 0.5; }
};

int main(int argc, char const *argv[]) { return 0; }
