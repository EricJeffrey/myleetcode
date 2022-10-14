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
    const int maxn = 10001;
    vector<int> father;

    int findfa(int x) {
        if (father[x] == x) return x;
        return father[x] = findfa(father[x]);
    }
    void unite(int x, int y) {
        int fx = findfa(x);
        int fy = findfa(y);
        father[fx] = fy;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        father.resize(maxn);
        for (size_t i = 0; i < father.size(); i++) {
            father[i] = i;
        }
        unordered_map<string, int> mail2index;
        for (auto &&vec : accounts) {
            for (size_t i = 1; i < vec.size(); i++) {
                const auto mail = vec[i];
                if (mail2index.find(mail) == mail2index.end()) mail2index[mail] = mail2index.size();
                if (i != 1) unite(mail2index[mail], mail2index[vec[i - 1]]);
            }
        }
        unordered_map<int, pair<string, set<string>>> resmap;
        for (auto &&vec : accounts) {
            auto name = vec[0];
            for (size_t i = 1; i < vec.size(); i++) {
                auto mail = vec[i];
                int fa = findfa(mail2index[mail]);
                if (resmap.find(fa) == resmap.end()) {
                    resmap[fa] = {name, {}};
                }
                resmap[fa].second.insert(mail);
            }
        }
        vector<vector<string>> res;
        for (auto &&fa2mails : resmap) {
            res.push_back({fa2mails.second.first});
            for (auto &&mail : fa2mails.second.second) {
                res.back().push_back(mail);
            }
        }
        for (auto &&vec : res) {
            if (vec.size() > 1) sort(vec.begin() + 1, vec.end());
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<string>> accounts;
    vector<vector<string>> res;
    accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"},
                {"John", "johnnybravo@mail.com"},
                {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                {"Mary", "mary@mail.com"}};
    res = Solution().accountsMerge(accounts);
    for (auto &&vec : res) {
        for (size_t i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    accounts = {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
                {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
                {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
                {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
                {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};
    res = Solution().accountsMerge(accounts);
    for (auto &&vec : res) {
        for (size_t i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
