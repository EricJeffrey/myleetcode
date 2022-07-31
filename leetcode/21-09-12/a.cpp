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
    string reversePrefix(string word, char ch) {
        auto it = word.find(ch);
        if (it != string::npos) 
            std::reverse(word.begin(), word.begin() + it + 1);
        return word;
    }
};

int main(int argc, char const *argv[]) {
    string s;
    char ch;
    
    cout << Solution().reversePrefix(s, ch) << endl;
    return 0;
}
