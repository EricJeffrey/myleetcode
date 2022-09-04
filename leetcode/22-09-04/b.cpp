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

void dfs(int start, int end, int k, int &cnt, vector<int> &s) {
    if (k <= 0) {
        if (start == end) {
            for (size_t i = 0; i < s.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << s[i];
            }
            cout << endl;
            cnt += 1;
        }
        return;
    }
    s.push_back(start - 1);
    dfs(start - 1, end, k - 1, cnt, s);
    s.pop_back();
    s.push_back(start + 1);
    dfs(start + 1, end, k - 1, cnt, s);
    s.pop_back();
}

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        if (startPos > endPos)
            swap(startPos, endPos);
        int cnt = k - (endPos - startPos);
        if (cnt < 0 || cnt % 2 == 1)
            return 0;
        if (cnt == 0)
            return 1;
        const int mod = 1e9 + 7;
        cnt = cnt / 2 + (endPos - startPos);
        // c k cnt
        /*
        1 1
        1 2 1
        1 3 3 1
         */
        vector<long long> tmps = {1, 1};
        vector<long long> news = {1};
        for (int i = 2; i <= k; i++) {
            for (int j = 0; j < i - 1; j++) {
                news.push_back((tmps[j + 1] + tmps[j]) % mod);
            }
            news.push_back(1);
            tmps = move(news);
            news = {1};
        }
        return static_cast<int>(tmps.at(cnt));
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().numberOfWays(2, 4, 6) << endl;
    return 0;
}

/*
2 1 0 1 2 3 4
2 1 2 1 2 3 4

2 1 2 3 2 3 4
2 1 2 3 4 3 4
2 1 2 3 4 5 4

2 3 2 1 2 3 4
2 3 2 3 2 3 4
2 3 4 3 2 3 4

2 3 2 3 4 3 4
2 3 2 3 4 5 4
2 3 4 3 4 3 4
2 3 4 3 4 5 4
2 3 4 5 4 3 4
2 3 4 5 4 5 4
2 3 4 5 6 5 4
15
0

 */