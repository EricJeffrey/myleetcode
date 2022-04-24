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
    int maximumCandies(vector<int> &candies, long long k) {
        int64_t sum = 0;
        for (auto &&v : candies) {
            sum += v;
        }
        if (sum < k)
            return 0;
        else if (sum < 2 * k)
            return 1;
        int l = 0, r = 1e7;
        auto check = [&candies, k](int v) {
            int64_t tmpk = 0;
            for (auto &&u : candies) {
                tmpk += u / v;
            }
            return tmpk >= k;
        };
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l != 0 && !check(l))
            l = l - 1;
        return l;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> candies;
    int k;
    candies = {5, 8, 6}, k = 3;
    cout << Solution().maximumCandies(candies, k) << endl;
    candies = {2, 5}, k = 11;
    cout << Solution().maximumCandies(candies, k) << endl;
    candies = {1, 2, 3, 4, 10}, k = 5;
    cout << Solution().maximumCandies(candies, k) << endl;
    return 0;
}
