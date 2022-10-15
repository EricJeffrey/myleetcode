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
    vector<int> productQueries(int n, vector<vector<int>> &queries) {
        vector<int> powers;
        for (int i = 0; i < 32; i++) {
            uint32_t v = 1u << i;
            if (((uint32_t)n) & v) powers.push_back(i);
        }
        vector<int64_t> prefix(powers.size() + 1, 0);
        prefix[1] = powers[0];
        for (size_t i = 1; i < powers.size(); i++) {
            prefix[i + 1] = powers[i] + prefix[i];
        }
        const int mod = 1e9 + 7;
        auto powmod2 = [mod](int x) {
            long long res = 1;
            for (int i = 0; i < x; i++) {
                res *= 2;
                res %= mod;
            }
            return (int)res;
        };
        vector<int> res;
        for (auto &&vec : queries) {
            int l = vec[0] + 1, r = vec[1] + 1;
            res.push_back(powmod2(prefix[r] - prefix[l - 1]));
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
