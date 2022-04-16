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
    int giveGem(vector<int> &gem, vector<vector<int>> &operations) {
        for (auto &&vec : operations) {
            int x = vec[0], y = vec[1];
            int num = floor(gem[x] / 2.0);
            gem[x] -= num;
            gem[y] += num;
        }
        return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
    }
};
int main(int argc, char const *argv[]) {

    return 0;
}
