#include <algorithm>
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
#include <vector>
using namespace std;

const int maxn = 1e7 + 5;

int occurIndex[maxn] = {};
int n;
vector<int> nums;
vector<vector<int>> factors;
vector<int> dps;

void gotFactors() {
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        for (int j = 1; j * j <= x; j++) {
            if (occurIndex[j] != -1 && x % j == 0) {
                factors[i].push_back(j);
                if (x / j != j && occurIndex[x / j] < i)
                    factors[i].push_back(x / j);
            }
        }
    }
}

int dfs(int index) {
    if (nums[index] == 1)
        return 1;
    if (dps[index] != -1)
        return dps[index];
    int tmpres = 1;
    for (int i = factors[index].size() - 1; i >= 0; i--) {
        int fac = factors[index][i];
        tmpres = max(tmpres, 1 + dfs(occurIndex[fac]));
    }
    return dps[index] = tmpres;
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        nums.push_back(x);
    }
    memset(occurIndex, -1, sizeof(occurIndex));
    factors.resize(n);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
        occurIndex[nums[i]] = i;
    gotFactors();
    for (int i = 0; i < n; i++)
        sort(factors[i].begin(), factors[i].end());
    dps.resize(n, -1);
    int res = 1;
    for (int i = n - 1; i >= 0; i--) {
        res = max(res, dfs(i));
    }
    printf("%d\n", res);

    return 0;
}
