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
    struct point {
        int x, y;
        bool operator<(const point &t) const {
            return x != t.x ? x > t.x : (y > t.y);
        }
    };
    int r;
    cin >> r;
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    map<point, int> point2cnt;
    auto calcRcovers = [&point2cnt, r](const point &p) {
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= r; j++) {
                if (i * i + j * j <= r * r) {
                    point2cnt[{p.x + i, p.y + j}]++;
                    if (i == 0 && j == 0)
                        continue;
                    else if (i != 0 && j != 0) {
                        point2cnt[{p.x - i, p.y + j}]++;
                        point2cnt[{p.x - i, p.y - j}]++;
                        point2cnt[{p.x + i, p.y - j}]++;
                    } else if (i != 0) {
                        point2cnt[{p.x - i, p.y + j}]++;
                    } else {
                        point2cnt[{p.x + i, p.y - j}]++;
                    }
                }
            }
        }
    };
    for (auto &&p : points) {
        calcRcovers(p);
    }
    point resp = {0, 0};
    int cnt = 0;
    for (auto &&p : point2cnt) {
        if (p.second > cnt || (p.second == cnt && (p.first.x > resp.x || (p.first.x == resp.x && p.first.y > resp.y)))) {
            cnt = p.second;
            resp = p.first;
        }
    }
    cout << resp.x << " " << resp.y << endl;
    return 0;
}
