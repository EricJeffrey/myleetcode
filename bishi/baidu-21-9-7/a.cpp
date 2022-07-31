#include <algorithm>
#include <array>
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

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            nums[i].push_back(x);
        }
    }
    vector<vector<int>> res(n * k, vector<int>(n * k, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v = nums[i][j];
            int starti = i * k, startj = j * k;
            for (int ii = 0; ii < k; ii++) {
                for (int jj = 0; jj < k; jj++) {
                    res[starti + ii][startj + jj] = v;
                }
            }
        }
    }
    for (auto &&vec : res) {
        for (auto &&v : vec) {
            cout << v << ' ';
        }
        cout << endl;
    }

    return 0;
}
