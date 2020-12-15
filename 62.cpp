#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  private:
  public:
    int uniquePaths(int m, int n) {
        int *dp = (int *)malloc(sizeof(int) * m);
        for (int i = 0; i < m; i++)
            dp[i] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[m - 1];
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().uniquePaths(1000, 1000) << endl;
    return 0;
}
