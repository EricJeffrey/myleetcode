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
#include <unordered_map>
#include <vector>
using namespace std;

#define maxn 102
#define maxval 30001
class Solution {
private:
    int min_pos[maxn];

public:
    vector<int> dailyTemperatures2(vector<int> &T) {
        const int n = T.size();
        vector<int> ret(T.size(), 0);
        if (n <= 1)
            return ret;
        for (int i = 0; i < maxn; i++) {
            min_pos[i] = maxval;
        }
        min_pos[T[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            int tmpVal = T[i], tmpMin = maxval;
            for (int j = tmpVal + 1; j < maxn; j++) {
                tmpMin = min(tmpMin, min_pos[j]);
            }
            if (tmpMin != maxval)
                ret[i] = tmpMin - i;
            min_pos[tmpVal] = min(i, min_pos[tmpVal]);
        }
        return ret;
    }
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> ret(T.size(), 0);
        stack<int> sta;
        for (int i = T.size() - 1; i >= 0; i--) {
            int tmpval = T[i];
            while (!sta.empty() && T[sta.top()] <= T[i]) {
                sta.pop();
            }
            if (!sta.empty())
                ret[i] = sta.top() - i;
            sta.push(i);
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
