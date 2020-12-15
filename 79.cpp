#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

typedef vector<char> VC;
class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        if (word.size() <= 0 || board.size() <= 0)
            return false;
        vector<vector<bool>> vis(board.size());
        for (int i = 0; i < board.size(); i++)
            vis[i] = vector<bool>(board[i].size(), false);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                const char ch = board[i][j];
                if (ch == word[0])
                    if (dfs(board, word, i, j, 1, vis))
                        return true;
            }
        }
        return false;
    }
    bool dfs(vector<VC> &board, string &word, int x, int y, int z, vector<vector<bool>> &vis) {
        if (z >= word.size())
            return true;
        vis[x][y] = true;
        const int iadd[4] = {1, 0, -1, 0}, jadd[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int tmpi = x + iadd[i], tmpj = y + jadd[i];
            if (tmpi < 0 || tmpi >= board.size() || tmpj < 0 || tmpj >= board[x].size() || vis[tmpi][tmpj])
                continue;
            if (board[tmpi][tmpj] == word[z] && dfs(board, word, tmpi, tmpj, z + 1, vis))
                return true;
        }
        vis[x][y] = false;
        return false;
    }
};