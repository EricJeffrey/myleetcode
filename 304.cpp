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

class NumMatrix {
    vector<vector<int>> preSumMatrix;

public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        preSumMatrix = matrix;
        for (size_t j = 1; j < preSumMatrix[0].size(); j++)
            preSumMatrix[0][j] += preSumMatrix[0][j - 1];
        for (size_t i = 1; i < preSumMatrix.size(); i++)
            preSumMatrix[i][0] += preSumMatrix[i - 1][0];

        for (size_t i = 1; i < preSumMatrix.size(); i++) {
            int tmpSum = matrix[i][0];
            for (size_t j = 1; j < preSumMatrix[i].size(); j++) {
                tmpSum += matrix[i][j];
                preSumMatrix[i][j] = tmpSum + preSumMatrix[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int r2c2 = preSumMatrix[row2][col2];
        int r2c1 = (col1 == 0 ? 0 : preSumMatrix[row2][col1 - 1]);
        int r1c2 = (row1 == 0 ? 0 : preSumMatrix[row1 - 1][col2]);
        int r1c1 = (row1 == 0 || col1 == 0 ? 0 : preSumMatrix[row1 - 1][col1 - 1]);
        return r2c2 - r2c1 - r1c2 + r1c1;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    NumMatrix *s = new NumMatrix(matrix);
    cout << s->sumRegion(2, 1, 4, 3) << endl;
    cout << s->sumRegion(1, 1, 2, 2) << endl;
    cout << s->sumRegion(1, 2, 2, 4) << endl;
    delete s;
    return 0;
}
