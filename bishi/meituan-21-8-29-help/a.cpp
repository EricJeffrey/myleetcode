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

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    int num2count[31] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        num2count[nums[i]] += 1;
    }
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int v = nums[i];
        int x = 0;
        for (int j = 0; j < v; j++)
        {
            if (num2count[j] > 0)
                x++;
        }
        res += x;
        num2count[v] -= 1;
    }
    cout << res << endl;

    return 0;
}
