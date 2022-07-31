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

int main(int argc, char const *argv[]) {
    vector<int> nums;
    map<int, vector<int>> age2poslist;
    int x;
    while (~scanf("%d", &x)) {
        age2poslist[x].push_back(nums.size());
        nums.push_back(x);
    }
    if (nums.size() == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (nums.size() == 2) {
        if (nums[0] == nums[1]) {
            cout << 2 << endl;
            return 0;
        } else {
            cout << 3 << endl;
            return 0;
        }
    }
    vector<int> res(nums.size(), 0);
    for (auto &&tmppair : age2poslist) {
        int curage = tmppair.first;
        for (auto &&pos : tmppair.second) {
            int lindex = (pos == 0 ? nums.size() - 1 : pos - 1);
            int rindex = (pos == nums.size() - 1 ? 0 : pos + 1);
            int lage = nums[lindex], rage = nums[rindex];
            int myNum = 1;
            if (curage > lage) {
                myNum = max(myNum, res[lindex] + 1);
            }
            if (curage > rage) {
                myNum = max(myNum, res[rindex] + 1);
            }
            res[pos] = myNum;
            // cout << "DEBUG, age:" << curage << ", pos:" << pos << ", myNum:" << myNum << endl;
        }
    }
    int ress = 0;
    for (auto &&v : res) {
        ress += v;
    }
    cout << ress << endl;

    return 0;
}
