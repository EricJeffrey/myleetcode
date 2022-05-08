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
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first = 0, second = 0;
        for (size_t i = 0; i < firstWord.size(); i++) {
            first *= 10;
            first += firstWord[i] - 'a';
        }
        for (size_t i = 0; i < secondWord.size(); i++) {
            second *= 10;
            second += secondWord[i] - 'a';
        }
        int third = 0;
        for (size_t i = 0; i < targetWord.size(); i++) {
            third *= 10;
            third += targetWord[i] - 'a';
        }
        if (first + second == third)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[]) {
    cout << "hello world" << endl;
    return 0;
}
