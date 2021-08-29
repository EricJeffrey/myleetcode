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
    string s, a;
    cin >> s;
    cin >> a;
    set<int> posofchar[27];
    for (size_t i = 0; i < s.size(); i++)
    {
        posofchar[s[i] - 'a'].insert((int)i);
    }
    bool ok = true;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (posofchar[a[i] - 'a'].empty())
        {
            ok = false;
            break;
        }
    }
    if (!ok)
    {
        cout << -1 << endl;
        return 0;
    }
    int numofs = 1;
    char lastch = a[0];
    int lastpos = *posofchar[lastch - 'a'].begin();
    for (size_t i = 1; i < a.size(); i++)
    {
        char ch = a[i];
        auto it = posofchar[ch - 'a'].upper_bound(lastpos);
        if (it == posofchar[ch - 'a'].end())
        {
            numofs += 1;
            lastpos = *posofchar[ch - 'a'].begin();
        }
        else
        {
            lastpos = *it;
        }
        lastch = ch;
    }
    cout << (numofs - 1) * s.size() + lastpos - a.size() + 1 << endl;

    return 0;
}
