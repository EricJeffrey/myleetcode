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

class Solution {
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
        int n = mat.size();
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            return true;
        ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[n - 1 - i][n - 1 - j] != target[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            return true;
        ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[n - 1 - j][i] != target[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            return true;
        ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[j][n - 1 - i] != target[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
        }
        return ok;
    }
};

int main(int argc, char const *argv[]) {
    //
    return 0;
}
