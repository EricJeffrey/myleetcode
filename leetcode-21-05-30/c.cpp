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

class Solution {
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        struct Server {
            int index;
            int weight;
            bool operator<(const Server &t) const {
                if (weight == t.weight)
                    return index < t.index;
                return weight < t.weight;
            }
        };
        struct BusyServer {
            int timetoend;
            int index;
            bool operator<(const BusyServer &t) {
                if (timetoend == t.timetoend)
                    return index < t.index;
                return timetoend < t.timetoend;
            }
            bool operator>(const BusyServer &t) const {
                if (timetoend == t.timetoend)
                    return index > t.index;
                return timetoend > t.timetoend;
            }
        };
        set<Server> freepool;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busyqueue;
        for (size_t i = 0; i < servers.size(); i++) {
            freepool.insert(Server{(int)i, servers[i]});
        }
        vector<int> res;
        int t = 0;
        int i = 0;
        while (i < tasks.size()) {
            if (t < i)
                t = i;
            while (!busyqueue.empty() && busyqueue.top().timetoend <= t) {
                int tmpindex = busyqueue.top().index;
                busyqueue.pop();
                freepool.insert(Server{tmpindex, servers[tmpindex]});
            }
            if (freepool.empty()) {
                t = busyqueue.top().timetoend;
            } else {
                auto &target = *freepool.begin();
                int tmpindex = freepool.begin()->index;
                res.push_back(tmpindex);
                freepool.erase(freepool.begin());
                busyqueue.push(BusyServer{t + tasks[i], tmpindex});
                i += 1;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
