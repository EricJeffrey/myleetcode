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

class Solution {
public:
    int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit) {
        int res = -1;
        int numLiaoli = cookbooks.size();
        for (int t = 1; t < (1 << numLiaoli); t++) {
            bitset<8> bs(t);
            bool ok = true;
            vector<int> numsPerMat(5, 0);
            for (int i = 0; i < numLiaoli; i++) {
                if (bs[i])
                    for (int j = 0; j < 5; j++)
                        numsPerMat[j] += cookbooks[i][j];
            }
            for (int i = 0; i < 5; i++) {
                if (numsPerMat[i] > materials[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                int baofu = 0;
                int meiwei = 0;
                for (int i = 0; i < numLiaoli; i++) {
                    if (bs[i]) {
                        baofu += attribute[i][1];
                        meiwei += attribute[i][0];
                    }
                }
                if (baofu >= limit) {
                    res = max(res, meiwei);
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {

    return 0;
}
