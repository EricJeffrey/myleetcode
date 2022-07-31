#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int mi, mj;
        mi = mj = (n + 1) >> 1;
        if (n & 1)
            mj -= 1;
        for (int i = 0; i < mi; i++) {
            for (int j = 0; j < mj; j++) {
                int a = matrix[i][j], x = i, y = j;
                for (int k = 0; k < 4; k++) {
                    int tmp = matrix[y][n - x - 1];
                    matrix[y][n - x - 1] = a;
                    a = tmp;
                    tmp = x;
                    x = y;
                    y = n - tmp - 1;
                }
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> m = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16},
    };
    // m = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    // };
    Solution().rotate(m);
    for (auto &&v : m) {
        for (auto &&tmp : v)
            cout << tmp << ' ';
        cout << endl;
    }
    return 0;
}
