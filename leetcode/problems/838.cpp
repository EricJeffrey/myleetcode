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
    string pushDominoes(string dominoes) {
        vector<int> vec;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                vec.push_back(i);
            }
        }
        vector<int> states(dominoes.size(), 0);
        while (vec.empty() == false) {
            fill(states.begin(), states.end(), 0);
            for (auto &&v : vec) {
                int next = dominoes[v] == 'L' ? v - 1 : v + 1;
                if (next >= 0 && next < dominoes.size() && dominoes[next] == '.') {
                    states[next] = states[next] + (dominoes[v] == 'L' ? -1 : 1);
                }
            }
            vec.clear();
            for (int i = 0; i < dominoes.size(); i++) {
                if (states[i] != 0) {
                    dominoes[i] = states[i] == -1 ? 'L' : 'R';
                    vec.push_back(i);
                }
            }
        }
        return dominoes;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().pushDominoes(".L.R...LR..L..") << endl;
    cout << Solution().pushDominoes("RR.L") << endl;
    return 0;
}
