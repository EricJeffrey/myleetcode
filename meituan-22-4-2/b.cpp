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

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<int64_t> prefsum(n, 0);
    prefsum[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefsum[i] = nums[i] + prefsum[i - 1];
    vector<int64_t> sufsum(n, 0);
    sufsum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
        sufsum[i] = nums[i] + sufsum[i + 1];

    vector<int64_t> prefn(n, 0);
    vector<int64_t> prefsummx(n, 0);
    prefsummx[0] = prefn[0] = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > prefn[i - 1])
            prefn[i] = nums[i];
        else
            prefn[i] = prefn[i - 1] + 1;
        prefsummx[i] = prefn[i] + prefsummx[i - 1];
    }

    vector<int64_t> sufn(n, 0);
    vector<int64_t> sufsummx(n, 0);
    sufsummx[n - 1] = sufn[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] > sufn[i + 1])
            sufn[i] = nums[i];
        else
            sufn[i] = sufn[i + 1] + 1;
        sufsummx[i] = sufn[i] + sufsummx[i + 1];
    }

    int64_t res = INT64_MAX;
    for (int i = 1; i <= n - 2; i++) {
        res = min(prefsummx[i - 1] + sufsummx[i + 1] + max(prefn[i], sufn[i]), res);
    }
    cout << res - sufsum[0] << endl;
    return 0;
}
