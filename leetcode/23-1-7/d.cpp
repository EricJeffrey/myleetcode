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
    bool check(const vector<long long> &dianlinags, long long target, int radius, int k) {
        vector<long long> prefix(dianlinags.size(), 0);
        for (int i = 0; i < dianlinags.size(); i++) {
            long long curdl = dianlinags[i];
            {
                long long start = i - radius;
                start = start <= 0 ? 0 : prefix[start - 1];
                long long end = i + radius - 1;
                end = end >= prefix.size() ? prefix.back() : prefix[end];
                curdl += (end - start);
            }
            int whoToBuf = i + radius;
            if (curdl < target) {
                /* need buf */
                if (whoToBuf >= prefix.size()) {
                    prefix.back() += target - curdl;
                } else {
                    prefix[whoToBuf] += target - curdl;
                }
            }
            if (whoToBuf < prefix.size()) {
                if (whoToBuf > 0) prefix[whoToBuf] += prefix[whoToBuf - 1];
            }
        }
        return prefix.back() <= k;
    }
    long long maxPower(vector<int> &stations, int radius, int k) {
        vector<long long> dainliangs(stations.size(), 0);
        {
            vector<long long> prefix(stations.size(), 0);
            prefix[0] = stations[0];
            for (size_t i = 1; i < stations.size(); i++) {
                prefix[i] = prefix[i - 1] + stations[i];
            }
            for (int i = 0; i < stations.size(); i++) {
                long long start = (i - radius);
                start = (start <= 0) ? 0 : prefix[start - 1];
                long long end = (i + radius);
                end = (end >= prefix.size()) ? prefix.back() : prefix[end];
                dainliangs[i] = end - start;
            }
        }
        long long l = 0, r = 1e11;
        while (l < r) {
            long long mid = (l + r) >> 1;
            bool ok = check(dainliangs, mid, radius, k);
            if (ok) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return check(dainliangs, l, radius, k) ? l : l - 1;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int r;
    int k;
    nums = {1, 2, 4, 5, 0};
    r = 1;
    k = 2;
    cout << Solution().maxPower(nums, r, k) << endl;
    return 0;
}
