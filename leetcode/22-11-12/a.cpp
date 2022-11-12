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
    int distinctAverages(vector<int> &nums) {
        multiset<int> ms;
        for (auto &&v : nums) {
            ms.insert(v);
        }
        set<int> ress;
        while (!ms.empty()) {
            int maxu = *ms.rbegin();
            int minu = *ms.begin();
            ress.insert(maxu + minu);
            ms.erase(ms.begin());
            ms.erase(ms.find(maxu));
        }
        return ress.size();
    }
};

int main(int argc, char const *argv[]) {
    //
    return 0;
}
