#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef vector<vector<int>> VG;
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() <= 0)
            return false;
        return sMatrix2(matrix, target);
        // int m = matrix.size(), n = matrix[0].size();
        // return sMatrix(0, 0, m, n, matrix, target);
    }
    // 从右上角依次找，每次可以排除一行或一列
    bool sMatrix2(VG &m, int t) {
        for (int j = m[0].size() - 1, i = 0; i < (int)m.size() && j >= 0;) {
            if (m[i][j] == t)
                return true;
            else if (m[i][j] < t)
                i++;
            else
                j--;
        }
        return false;
    }
    // 对角线值分隔，递归搜索
    bool sMatrix(int li, int lj, int m, int n, VG &matrix, int target) {
        if (m == 1 || n == 1) {
            // 一行 一列 二分
            int l = lj, r = lj + n - 1, who = 0;
            n == 1 ? (l = li, r = li + m - 1, who = 1) : 0;
            while (l <= r) {
                int mid = (l + r + 1) >> 1;
                const int v = (who == 0 ? matrix[li][mid] : matrix[mid][lj]);
                if (v < target)
                    l = mid + 1;
                else if (v > target)
                    r = mid - 1;
                else
                    return true;
            }
            return false;
        }
        // 沿对角线找小于 target 的最大值
        int lecnt = 0, l = li, r = li + min(m, n) - 1;
        while (l <= r) {
            int mid = (l + r + 1) >> 1;
            const int v = matrix[mid][lj + (mid - li)];
            if (v < target)
                l = mid + 1;
            else if (v > target)
                r = mid - 1;
            else
                return true;
        }
        lecnt = l - li;
        // 最大正方形所有值都小于 target
        if (lecnt == 0) {
            return false;
        } else if (lecnt == m || lecnt == n) {
            if (m != n) {
                int nli = li, nlj = lj, nm = m, nn = n;
                m < n ? (nlj += m, nn -= m) : (nli += n, nm -= n);
                return sMatrix(nli, nlj, nm, nn, matrix, target);
            }
            return false;
        } else {
            if (sMatrix(li + lecnt, lj, m - lecnt, lecnt, matrix, target))
                return true;
            return sMatrix(li, lj + lecnt, lecnt, n - lecnt, matrix, target);
        }
    }
};

int main(int argc, char const *argv[]) {
    VG m;
    m = {{1, 4, 7, 11, 15},
         {2, 5, 8, 12, 19},
         {3, 6, 9, 16, 22},
         {10, 13, 14, 17, 24},
         {18, 21, 23, 26, 30}};
    m = {{4, 7, 11, 12, 16, 21, 23, 26},   {5, 12, 17, 17, 18, 23, 26, 31},
         {8, 15, 21, 25, 26, 29, 33, 34},  {13, 20, 26, 26, 29, 34, 39, 40},
         {18, 21, 31, 36, 41, 42, 42, 44}, {19, 23, 31, 39, 46, 49, 50, 53},
         {23, 25, 33, 40, 50, 51, 55, 60}, {27, 28, 33, 44, 51, 56, 61, 65},
         {32, 35, 39, 45, 54, 56, 65, 68}, {33, 38, 40, 49, 56, 57, 66, 71},
         {34, 39, 41, 52, 59, 62, 68, 82}};
    Solution s;
    for (auto &&vec : m) {
        for (auto &&v : vec) {
            cout << (s.searchMatrix(m, v) ? "true" : "false") << endl;
        }
    }
    int t;
    while (cin >> t) {
        cout << (s.searchMatrix(m, t) ? "true" : "false") << endl;
    }
    return 0;
}
/*
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
*/
