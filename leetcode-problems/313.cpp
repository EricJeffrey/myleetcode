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

// TLE。。。
// class Solution {
// public:
//     int dfs(const vector<int> &nums, int start, double upper) {
//         if (start >= nums.size())
//             return 0;
//         if (upper - nums[start] < -1e-9)
//             return 0;
//         int ret = dfs(nums, start + 1, upper) + 1 + dfs(nums, start, upper / nums[start]);
//         return ret;
//     }
//     int nthSuperUglyNumber(int n, vector<int> &primes) {
//         if (n == 1)
//             return 1;
//         int64_t l = 0, r = INT32_MAX;
//         while (l < r) {
//             int tmp = dfs(primes, 0, (l + r) >> 1) + 1;
//             if (tmp >= n)
//                 r = (l + r) >> 1;
//             else if (tmp < n)
//                 l = ((l + r) >> 1) + 1;
//         }
//         return l;
//     }
// };

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        // reverse(primes.begin(), primes.end());
        vector<int> values(n + 1, 0);
        values[0] = 1;
        vector<int> tmpvec(primes.size(), 0);
        vector<int> pointers(primes.size(), 0);
        for (int i = 1; i < n; i++) {
            int tmpmin = INT32_MAX;
            int used_prime_index = -1;
            for (size_t i = 0; i < primes.size(); i++) {
                int v = primes[i] * values[pointers[i]];
                tmpmin = min(tmpmin, v);
                tmpvec[i] = v;
            }
            // HERE!!!
            for (size_t i = 0; i < primes.size(); i++) {
                if (tmpvec[i] == tmpmin)
                    pointers[i] += 1;
            }
            values[i] = (tmpmin);
        }
        return values[n - 1];
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,
                        53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                        127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
                        199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                        283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
                        383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
                        467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
    // nums = {239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337,
    //         347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
    //         443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557,
    //         563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653,
    //         659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769,
    //         773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883,
    //         887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    // nums = {2, 7, 13, 19};
    int n;
    while (cin >> n) {
        cout << Solution().nthSuperUglyNumber(n, nums) << endl;
    }
    return 0;
}
