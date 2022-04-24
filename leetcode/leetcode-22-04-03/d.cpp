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

class Encrypter {
    vector<string> dict;
    vector<char> keys;
    vector<string> values;
    vector<size_t> ch2i;
    vector<vector<bitset<26>>> v2bs;

public:
    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary)
        : keys(keys), values(values), dict(dictionary) {
        ch2i.resize(26, 0);
        for (int i = 0; i < keys.size(); i++) {
            ch2i[keys[i] - 'a'] = i;
        }
        v2bs.resize(26, vector<bitset<26>>(26, bitset<26>(0)));
        for (size_t i = 0; i < values.size(); i++) {
            int ch = keys[i] - 'a';
            v2bs[values[i][0] - 'a'][values[i][1] - 'a'].set(ch, true);
        }
    }

    string encrypt(string word1) {
        vector<string> resvec;
        for (size_t i = 0; i < word1.size(); i++) {
            int ch = word1[i] - 'a';
            resvec.push_back(values[ch2i[ch]]);
        }
        string res;
        for (auto &&s : resvec)
            res += s;
        return res;
    }

    int decrypt(string word2) {
        vector<bitset<26>> debs;
        debs.reserve(word2.size() / 2);
        for (size_t i = 0; i < word2.size(); i += 2) {
            int ch1 = word2[i] - 'a', ch2 = word2[i + 1] - 'a';
            debs.push_back(v2bs[ch1][ch2]);
        }
        int res = 0;
        for (auto &&s : dict) {
            if (s.size() != debs.size())
                continue;
            bool ok = true;
            for (size_t i = 0; i < s.size(); i++) {
                if (debs[i][s[i] - 'a'] == false) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                res += 1;
        }
        return res;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */