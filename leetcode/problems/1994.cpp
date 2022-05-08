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
    int numberOfGoodSubsets(vector<int> &nums) {
        static const vector<int> a = {2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30};
        static const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        static vector<int> nummap(31, 0);
        static vector<int> asets;
        if (asets.empty()) {
            for (int i = 1; i <= 30; i++) {
                int v = 0;
                for (int j = primes.size() - 1; j >= 0; j--) {
                    v <<= 1;
                    auto p = primes[j];
                    if (i % p == 0) {
                        if (i % (p * p) == 0) {
                            v = 0;
                            break;
                        } else {
                            v |= 1;
                        }
                    }
                }
                nummap[i] = v;
            }
            // for (auto &&v : nummap) {
            //     cout << v << " ";
            // }
            // cout << endl;

            auto check = [](const vector<int> &vec) {
                for (size_t i = 0; i < vec.size(); i++) {
                    for (size_t j = i + 1; j < vec.size(); j++) {
                        if ((nummap[vec[i]] & nummap[vec[j]]) != 0)
                            return false;
                    }
                }
                return true;
            };
            vector<int> tmpvec;
            for (int i = 0; i < (1 << a.size()); i++) {
                tmpvec.clear();
                for (size_t j = 0; j < a.size(); j++) {
                    if ((i & (1 << j)) != 0) {
                        tmpvec.push_back(a[j]);
                    }
                }
                if (tmpvec.empty() == false && check(tmpvec))
                    asets.push_back(i);
            }
            // for (auto &&v : asets) {
            //     cout << v << " ";
            // }
            // cout << endl;
        }
        vector<int> cntofnum(31, 0);
        for (auto &&v : nums) {
            cntofnum[v] += 1;
        }
        static int mod = 1e9 + 7;
        int res = 0;
        for (auto &&tmps : asets) {
            vector<int> tmpvec;
            for (size_t i = 0; i < a.size(); i++) {
                if ((tmps & (1 << i)) != 0)
                    tmpvec.push_back(a[i]);
            }
            long long tmp = 1;
            for (auto &&v : tmpvec) {
                tmp *= cntofnum[v];
                tmp %= mod;
            }
            // cout << tmps << ": ";
            // for (auto &&v : tmpvec) {
            //     cout << v << ",";
            // }
            // cout << ": " << tmp << endl;

            res += (int)tmp;
            res %= mod;
        }
        for (int i = 0; i < cntofnum[1]; i++) {
            res *= 2;
            res %= mod;
        }

        return res;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> nums;
    auto s = Solution();
    nums = {4, 2, 3, 15};
    cout << s.numberOfGoodSubsets(nums) << endl;
    nums = {1, 2, 3, 4};
    cout << s.numberOfGoodSubsets(nums) << endl;
    nums = {26, 25, 10, 3, 14, 21, 6, 12};
    cout << s.numberOfGoodSubsets(nums) << endl;
    return 0;
}
