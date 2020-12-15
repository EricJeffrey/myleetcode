#include <algorithm>
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

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        struct T {
            int value, count;
            int asEndCnt;
        };
        if (nums.size() < 3)
            return false;
        vector<T> values;
        for (auto &&v : nums) {
            if (values.empty() || values.back().value != v)
                values.push_back(T{v, 1, 0});
            else
                values.back().count += 1;
        }
        if (values.size() < 3)
            return false;
        for (size_t i = 0; i < values.size(); i++) {
            for (int j = 0; j < values[i].count; j++) {
                if (i != 0 && values[i].value - values[i - 1].value == 1 && values[i - 1].asEndCnt > 0) {
                    values[i - 1].asEndCnt -= 1;
                    values[i].asEndCnt += 1;
                } else if (i + 2 < values.size() &&
                           values[i + 1].count > 0 &&
                           values[i + 2].count > 0 &&
                           values[i + 1].value - values[i].value == 1 &&
                           values[i + 2].value - values[i + 1].value == 1) {
                    values[i + 1].count -= 1;
                    values[i + 2].count -= 1;
                    values[i + 2].asEndCnt += 1;
                } else
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](vector<int> nums) {
        cout << (Solution().isPossible(nums) ? "true" : "false") << endl;
    };
    testout({1, 2, 3, 3, 4, 5});
    testout({1, 2, 3, 3, 4, 4, 5, 5});
    testout({1, 2, 3, 4, 4, 5});
    testout({1, 2, 3, 3, 4, 4, 5, 6});
    testout({3, 4, 4, 5, 6, 7, 8, 9, 10, 11});
    return 0;
}
