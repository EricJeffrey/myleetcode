#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        int letters[26] = {}, tot = 0;
        for (string s : strs) {
            memset(letters, 0, sizeof(letters));
            for (char ch : s)
                letters[ch - 'a']++;
            string key;
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(letters[i]);
            }
            if (mp.find(key) != mp.end()) {
                res[mp[key]].push_back(s);
            } else {
                vector<string> tmp;
                tmp.push_back(s);
                res.push_back(tmp);
                mp[key] = tot++;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) { return 0; }
