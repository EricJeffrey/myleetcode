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

int main(int argc, char const *argv[]) {
    vector<int64_t> nums;
    int x;
    while (~scanf(" %d", &x)) {
        nums.push_back(x);
    }
    int64_t m = nums.back();
    nums.pop_back();
    int64_t res = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] <= m)
                res++;
        }
    }
    printf("%d\n", res);

    return 0;
}
