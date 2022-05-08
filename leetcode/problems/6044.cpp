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
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        typedef pair<int, int> pii;
        sort(flowers.begin(), flowers.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] < v2[1];
        });
        vector<pii> nps(persons.size());
        for (int i = 0; i < persons.size(); i++) {
            nps[i] = {persons[i], i};
        }
        sort(nps.begin(), nps.end(), [](const pii &p1, const pii &p2) {
            return p1.first < p2.first;
        });
        struct T {
            int s, e;
            bool operator>(const T &t) const {
                return e > t.e;
            }
        };
        priority_queue<T, vector<T>, greater<T>> q;
        vector<int> res(persons.size(), 0);
        int nexti = 0;
        for (auto &&p : nps) {
            while (!q.empty() && q.top().e < p.first)
                q.pop();
            for (; nexti < flowers.size(); nexti++) {
                if (flowers[nexti][0] > p.first)
                    break;
                if (flowers[nexti][1] >= p.first)
                    q.push({flowers[nexti][0], flowers[nexti][1]});
            }
            if (!q.empty())
                res[p.second] = q.size();
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> flowers;
    vector<int> persons;
    flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    persons = {2, 3, 7, 11};
    for (auto &&v : Solution().fullBloomFlowers(flowers, persons)) {
        cout << v << " ";
    }
    cout << endl;

    flowers = {{1, 10}, {3, 3}};
    persons = {3, 3, 2};
    for (auto &&v : Solution().fullBloomFlowers(flowers, persons)) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
