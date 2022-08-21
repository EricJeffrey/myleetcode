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

string work(int n, int k1, int k2, int p, const vector<int> &nums) {
    vector<long long> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    string res(n, '0');
    auto calcSum = [&prefix](int end, int len) {
        int start = end - len + 1;
        if (start == 0) {
            return prefix[end];
        }
        return prefix[end] - prefix[start - 1];
    };
    for (int i = k2 - 1; i < n; i++) {
        long long k1Sum = calcSum(i, k1);
        long long k2Sum = calcSum(i, k2);
        if (k1Sum * k2 * 100 < k2Sum * k1 * p) {
            res[i] = '1';
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int k1, k2, p;
        cin >> k1 >> k2 >> p;
        cout << work(n, k1, k2, p, nums) << endl;
    }
}