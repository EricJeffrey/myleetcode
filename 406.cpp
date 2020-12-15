
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    vector<pair<int, int>> reconstructQueue_1(vector<pair<int, int>> &people) {
        vector<pair<int, int>> res;
        typedef pair<int, int> PII;
        vector<pair<PII, int>> tmpP;
        for (auto &&p : people) {
            tmpP.push_back(pair<PII, int>(p, 0));
        }
        int sz = people.size();
        for (int i = 0; i < sz; i++) {
            int min_i = i;
            for (int j = i; j < sz; j++) {
                int jff = tmpP[j].first.first, jfs = tmpP[j].first.second;
                int miff = tmpP[min_i].first.first,
                    mifs = tmpP[min_i].first.second;
                if (jfs == 0 && (mifs != 0 || miff > jff))
                    min_i = j;
            }
            swap(tmpP[i], tmpP[min_i]);
            PII tmp = tmpP[i].first;
            tmp.second += tmpP[i].second;
            res.push_back(tmp);
            for (int j = i + 1; j < sz; j++) {
                if (tmpP[j].first.first <= tmpP[i].first.first) {
                    tmpP[j].first.second -= 1;
                    tmpP[j].second += 1;
                }
            }
        }
        return res;
    }
    bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first >= b.first;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        sort(people.begin(), people.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first >= b.first;
             });
        vector<pair<int, int>> res;
        for (auto &&p : people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};
int main() {
    vector<pair<int, int>> people = {
        pair<int, int>(7, 0), pair<int, int>(4, 4), pair<int, int>(7, 1),
        pair<int, int>(5, 0), pair<int, int>(6, 1), pair<int, int>(5, 2)};
    vector<pair<int, int>> res = Solution().reconstructQueue(people);
    for (auto &&p : res) {
        cout << p.first << ", " << p.second << endl;
    }

    return 0;
}
