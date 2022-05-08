#include <algorithm>
#include <array>
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

/*  

第一题签到
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int a[26] = {};
        for (size_t i = 0; i < sentence.size(); i++) {
            a[sentence[i] - 'a'] = 1;
        }
        for (auto &&v : a) {
            if (v == 0)
                return false;
        }
        return true;
    }
};

第二题签到，直接贪心
class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        int tmpCoins = coins;
        for (auto &&v : costs) {
            if (v <= tmpCoins) {
                tmpCoins -= v;
                res += 1;
            } else
                break;
        }
        return res;
    }
};

第三题略复杂，不过也是贪心
class Solution {
public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        struct Cmp {
            int enqueTime, processTime;
            int index;
            // used for sort
            bool operator<(const Cmp &t) const {
                if (enqueTime < t.enqueTime)
                    return true;
                else if (enqueTime == t.enqueTime)
                    return processTime < t.processTime;
                return false;
            }
            bool operator>(const Cmp &t) const {
                if (processTime > t.processTime)
                    return true;
                else if (processTime == t.processTime)
                    return index > t.index;
                return false;
            }
        };
        vector<Cmp> allTasks;
        for (int i = 0; i < tasks.size(); i++) {
            auto &v = tasks[i];
            allTasks.push_back({v[0], v[1], i});
        }
        sort(allTasks.begin(), allTasks.end());
        int next = 0;
        long long now = 0;
        vector<int> res;
        priority_queue<Cmp, vector<Cmp>, greater<Cmp>> q;
        while (next < tasks.size()) {
            if (q.empty()) {
                auto tmp = allTasks[next];
                q.push(tmp);
                next += 1;
                now = tmp.enqueTime;
            }
            while (!q.empty()) {
                auto tmp = q.top();
                q.pop();
                for (next;
                     next < allTasks.size() && allTasks[next].enqueTime <= now + tmp.processTime;
                     next++) {
                    q.push(allTasks[next]);
                }
                res.push_back(tmp.index);
                now += tmp.processTime;
            }
        }
        return res;
    }
};


第四题 - 思维
class Solution {
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2) {
        int a2Xor = arr2[0];
        for (size_t i = 1; i < arr2.size(); i++) {
            a2Xor ^= arr2[i];
        }
        int res = arr1[0] & a2Xor;
        for (size_t i = 1; i < arr1.size(); i++) {
            res ^= arr1[i] & a2Xor;
        }
        return res;
    }
}; 
*/

int main(int argc, char const *argv[]) {
    //
    return 0;
}
