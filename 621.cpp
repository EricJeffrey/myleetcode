#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        int vec[26] = {};
        for (char ch : tasks)
            vec[ch - 'A']++;
        sort(vec, vec + 26);
        int i = 25;
        while (i >= 0 && vec[i] == vec[25])
            i--;
        return max((int)tasks.size(), (vec[25] - 1) * (n + 1) + 25 - i);
    }
};

int main(int argc, char const *argv[]) {
    vector<char> vec;
    vec = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'B',
           'B', 'B', 'C', 'C', 'C', 'D', 'D'};
    cout << Solution().leastInterval(vec, 2) << endl;
    return 0;
}
