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

int main(int argc, char const *argv[]) {
    vector<int> nums = {15, 45, 20, 2, 34, 35, 5, 44, 32, 30};
    vector<int> vs;
    for (size_t i = 0; i < nums.size(); i++) {
        for (size_t j = 0; j < nums.size(); j++) {
            for (size_t k = 0; k < nums.size(); k++) {
                int v = (nums[i] | nums[j]) & nums[k];
                printf("(%d | %d) & %d = %d\n", nums[i], nums[j], nums[k], v);
                vs.push_back(v);
            }
        }
    }
    for (auto &&v : vs) {
        printf("%d ^ ", v);
    }
    puts("");

    return 0;
}
