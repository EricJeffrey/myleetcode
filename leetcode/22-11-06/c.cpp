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
    long long totalCost(vector<int> &costs, int k, int candidates) {
        typedef pair<int, int> pii;

        int n = costs.size();
        multiset<pii> lset;
        int li = 0;
        multiset<pii> rset;
        int ri = 0;
        for (int i = 0; i < candidates; i++) {
            lset.insert({costs[i], i});
            li = i;
            if (n - 1 - i > candidates - 1) {
                rset.insert({costs[n - 1 - i], n - 1 - i});
                ri = n - 1 - i;
            }
        }
        long long res = 0;
        for (int i = 0; i < k; i++) {
            if (rset.empty() || !lset.empty() && *lset.begin() <= *rset.begin()) {
                res += lset.begin()->first;
                lset.erase(lset.begin());
                if (li + 1 < ri) lset.insert({costs[li + 1], li + 1});
                li += 1;
            }
            else if (lset.empty() || !rset.empty() && *lset.begin() > *rset.begin()) {
                res += rset.begin()->first;
                rset.erase(rset.begin());
                if (ri - 1 > li) rset.insert({costs[ri - 1], ri - 1});
                ri -= 1;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> costs;
    int k, candidates;
    costs = {1, 2, 4, 1}, k = 3, candidates = 3;
    cout << Solution().totalCost(costs, k, candidates) << endl;
    return 0;
}
