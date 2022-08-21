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
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy,
                         vector<int> &experience) {
        int res = 0;
        int curEnergy = initialEnergy;
        int curExp = initialExperience;
        for (size_t i = 0; i < energy.size(); i++) {
            if (curEnergy <= energy[i]) {
                res += energy[i] + 1 - curEnergy;
                curEnergy = energy[i] + 1;
            }
            if (curExp <= experience[i]) {
                res += experience[i] + 1 - curExp;
                curExp = experience[i] + 1;
            }
            curEnergy -= energy[i];
            curExp += experience[i];
        }
        return res;
    }
};