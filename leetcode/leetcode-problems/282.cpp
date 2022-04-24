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

// 38231122 48
/*
3+8+23*1+12+2

 */

int dfs(const string &num, size_t start, bool neg, long long target, vector<long long> preds,
        deque<pair<int, int>> &opstack, vector<string> &res_set) {
    static vector<char> ops = {'+', '-', '*'};
    if (start >= num.size()) {
        if ((preds.empty() && target == 0) || (preds.empty() == false && target == preds[0])) {
            auto tmpstack = opstack;
            int last_i = 0;
            string res;
            // cout << endl << "-----DEBUG-----" << endl;
            while (tmpstack.empty() == false) {
                auto p = tmpstack.front();
                tmpstack.pop_front();
                auto tmps = num.substr(last_i, p.first - last_i);
                if (tmps.size() > 1 && tmps[0] == '0')
                    return 0;
                res += tmps;
                res += ops[p.second];
                last_i = p.first;
                // cout << "(" << p.first << ", " << p.second << ") ";
            }
            // cout << endl;

            auto tmps = num.substr(last_i, num.size() - last_i);
            if (tmps.size() > 1 && tmps[0] == '0')
                return 1;
            res += tmps;
            res_set.push_back(res);
        }
        return 1;
    }
    if (preds.empty()) {
        for (size_t i = start + 1; i <= num.size(); i++) {
            auto v = stoll(num.substr(start, i - start));
            if (neg)
                v = -v;
            if (i == num.size()) {
                dfs(num, i, false, target - v, preds, opstack, res_set);
                break;
            }
            // +
            opstack.push_back(make_pair(i, 0));
            dfs(num, i, false, target - v, preds, opstack, res_set);
            opstack.pop_back();
            // -
            opstack.push_back(make_pair(i, 1));
            dfs(num, i, true, target - v, preds, opstack, res_set);
            opstack.pop_back();
            // *
            opstack.push_back(make_pair(i, 2));
            for (size_t j = i + 1; j <= num.size(); j++) {
                auto u = stoll(num.substr(i, j - i));
                dfs(num, j, false, target, {u * v}, opstack, res_set);
            }
            opstack.pop_back();
        }
    } else {
        // +
        opstack.push_back(make_pair(start, 0));
        dfs(num, start, false, target - preds[0], {}, opstack, res_set);
        opstack.pop_back();
        // -
        opstack.push_back(make_pair(start, 1));
        dfs(num, start, true, target - preds[0], {}, opstack, res_set);
        opstack.pop_back();
        // *
        opstack.push_back(make_pair(start, 2));
        for (size_t j = start + 1; j <= num.size(); j++) {
            auto u = stoll(num.substr(start, j - start));
            dfs(num, j, false, target, {u * preds[0]}, opstack, res_set);
        }
        opstack.pop_back();
    }
    return 0;
}

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        deque<pair<int, int>> opstack;
        dfs(num, 0, false, target, {}, opstack, res);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    //
    auto work = [&](string num, int target) {
        vector<string> res = Solution().addOperators(num, target);
        if (set<string>(res.begin(), res.end()).size() != res.size())
            cout << "FAIL! " << endl;
        else
            cout << "TRUE! " << endl;
        for (auto v : res)
            cout << v << ",";
        cout << endl;
    };
    while (true) {
        string num;
        cin >> num;
        int target;
        cin >> target;
        work(num, target);
        break;
    }

    work("232", 8);
    work("36215", 34);
    work("2353814", 32);
    work("3456237490", 9191);
    return 0;
}
