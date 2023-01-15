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

class DataStream {
public:
    deque<int> nums;
    int value;
    int k;
    int lastNoValIndex;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        lastNoValIndex = -1;
    }

    bool consec(int num) {
        nums.push_back(num);
        if (nums.size() > k) {
            nums.pop_back();
            lastNoValIndex -= 1;
        }
        if (num != value) {
            lastNoValIndex = nums.size() - 1;
        }
        if (nums.size() < k || lastNoValIndex >= 0) {
            return false;
        }
        return true;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
