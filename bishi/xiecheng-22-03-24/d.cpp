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
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> matrix;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        matrix.push_back(s);
    }
    auto flip = [](char ch) {
        if (islower(ch))
            return toupper(ch);
        else
            return tolower(ch);
    };
    vector<vector<int>> ops(n, vector<int>(m + 1, 0));
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 1;
        x2 -= 1;
        y1 -= 1;
        y2 -= 1;
        for (int j = x1; j <= x2; j++) {
            ops[j][y1] += 1;
            ops[j][y2 + 1] -= 1;
        }
    }
    vector<vector<int>> pref(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        pref[i][0] = ops[i][0];
        for (int j = 1; j < m; j++) {
            pref[i][j] = ops[i][j] + pref[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pref[i][j] % 2 != 0) {
                matrix[i][j] = flip(matrix[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << matrix[i] << endl;
    }
    return 0;
}
