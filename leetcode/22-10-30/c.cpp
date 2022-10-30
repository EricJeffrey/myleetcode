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
    long long work(string &ns, int start, int target) {
        int prefix = 0;
        int i = start;
        while (i < ns.size() && prefix + ns[i] - '0' <= target) {
            prefix += ns[i] - '0';
            i += 1;
        }
        if (i == start) {
            return -1;
        }
        if (i >= ns.size()) return 0;
        i -= 1;
        long long tmp = work(ns, i + 1, target - prefix);
        if (tmp == -1) {
            int j = i + 1;
            long long total = 1;
            long long leftv = 0;
            while (j < ns.size()) {
                leftv = leftv * 10 + ns[j] - '0';
                total = total * 10;
                ns[j] = '0';
                j += 1;
            }
            leftv = total - leftv;
            j = i;
            ns[j] += 1;
            prefix = 0;
            while (j >= 0) {
                if (ns[j] - '0' >= 10) {
                    ns[j] = '0';
                    if (j == 0) {
                        // ns = "1" + ns;
                        prefix += 1;
                        break;
                    }
                    ns[j - 1] += 1;
                }
                prefix += ns[j] - '0';
                j -= 1;
            }
            tmp = leftv + work(ns, start, target);
        }
        return tmp;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        string ns = to_string(n);
        ns = "0" + ns;
        return work(ns, 0, target);
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().makeIntegerBeautiful(16, 6) << endl;
    cout << Solution().makeIntegerBeautiful(246, 6) << endl;
    cout << Solution().makeIntegerBeautiful(467, 6) << endl;
    cout << Solution().makeIntegerBeautiful(1, 1) << endl;
    cout << Solution().makeIntegerBeautiful(67, 6) << endl;
    cout << Solution().makeIntegerBeautiful(11359821123655, 8) << endl;
    cout << Solution().makeIntegerBeautiful(11359821123655, 5) << endl;
    cout << Solution().makeIntegerBeautiful(1, 5) << endl;
    return 0;
}
