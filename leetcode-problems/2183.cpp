
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

int gcd(int a, int b) {
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b == 0 ? 1 : b;
    return gcd(b % a, a);
}
class Solution {
public:
    long long countPairs(vector<int> &nums, int k) {
        vector<int> allfactors;
        for (int i = 1; i <= int(round(sqrt(k))); i++) {
            if (k % i == 0) {
                allfactors.push_back(i);
                allfactors.push_back(k / i);
            }
        }
        map<int, int> cnts;
        for (auto &&v : allfactors) {
            int cnt = 0;
            for (auto &&num : nums) {
                if (num % v == 0)
                    cnt += 1;
            }
            cnts[v] = cnt;
        }
        long long res = 0;
        for (auto &&num : nums) {
            int v = k / gcd(num, k);
            res += cnts[v] - (num % v == 0 ? 1 : 0);
        }
        return res / 2;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int k;
    nums = {1, 2, 3, 4, 5}, k = 2;
    cout << Solution().countPairs(nums, k) << endl;
    nums = {1, 2, 3, 4}, k = 5;
    cout << Solution().countPairs(nums, k) << endl;
    return 0;
}
