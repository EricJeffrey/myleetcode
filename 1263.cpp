#include <algorithm>
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

typedef vector<vector<char>> VCC;
struct Pos {
    int row, col;
    bool operator==(const Pos &t) {
        return row == t.row && col == t.col;
    }
};

vector<Pos> moveHelper = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool checkInside(VCC &grid, Pos pos) {
        return pos.row >= 0 && pos.row < (int)grid.size() && pos.col >= 0 && pos.col < (int)grid[pos.row].size();
    }
    bool bfsCheckPlayer(VCC &grid, Pos playerPos, Pos playerToPos, Pos boxPos) {
        if (playerToPos == boxPos || playerPos == boxPos)
            return false;
        vector<vector<bool>> visited(grid.size());
        for (size_t i = 0; i < grid.size(); i++) {
            if (visited[i].empty())
                visited[i] = vector<bool>(grid[i].size(), false);
            fill(visited[i].begin(), visited[i].end(), false);
        }
        queue<Pos> q;
        q.push(playerPos);
        visited[playerPos.row][playerPos.col] = true;
        while (!q.empty()) {
            Pos u = q.front();
            q.pop();
            if (u == playerToPos)
                return true;
            for (auto &&helper : moveHelper) {
                Pos vPos{u.row + helper.row, u.col + helper.col};
                if (checkInside(grid, vPos) &&
                    !(vPos == boxPos) &&
                    !visited[vPos.row][vPos.col] &&
                    grid[vPos.row][vPos.col] != '#') {
                    q.push(vPos);
                    visited[vPos.row][vPos.col] = true;
                }
            }
        }
        return false;
    }

    int bfsBox(VCC &grid, Pos initPlayerPos, Pos initBoxPos, Pos targetPos) {
        struct QElement {
            Pos playerPos, boxPos;
            int cnt;
        };

        vector<vector<vector<vector<bool>>>> visited;
        for (size_t i = 0; i < grid.size(); i++) {
            visited.push_back({});
            for (size_t j = 0; j < grid[i].size(); j++) {
                visited[i].push_back({});
                for (size_t k = 0; k < grid.size(); k++)
                    visited[i][j].push_back(vector<bool>(grid[k].size(), false));
            }
        }

        queue<QElement> q;
        q.push(QElement{initPlayerPos, initBoxPos, 0});
        while (!q.empty()) {
            QElement u = q.front();
            q.pop();
            if (u.boxPos == targetPos)
                return u.cnt;
            for (auto &&helper : moveHelper) {
                Pos vBoxPos = {u.boxPos.row + helper.row, u.boxPos.col + helper.col};
                Pos vPlayerToPos = {u.boxPos.row - helper.row, u.boxPos.col - helper.col};
                if (checkInside(grid, vBoxPos) &&
                    checkInside(grid, vPlayerToPos) &&
                    (!visited[vBoxPos.row][vBoxPos.col][u.boxPos.row][u.boxPos.col]) &&
                    (grid[vBoxPos.row][vBoxPos.col] == '.' || grid[vBoxPos.row][vBoxPos.col] == 'T') &&
                    grid[vPlayerToPos.row][vPlayerToPos.col] == '.' &&
                    bfsCheckPlayer(grid, u.playerPos, vPlayerToPos, u.boxPos)) {

                    // player will always move to pos of box after push
                    q.push(QElement{u.boxPos, vBoxPos, u.cnt + 1});
                    visited[vBoxPos.row][vBoxPos.col][u.boxPos.row][u.boxPos.col] = true;
                };
            }
        }
        return -1;
    }

    int minPushBox(vector<vector<char>> &grid) {
        Pos initPlayerPos, initBoxPos;
        Pos targetPos;
        for (int i = 0; i < (int)grid.size(); i++)
            for (int j = 0; j < (int)grid[i].size(); j++)
                if (grid[i][j] == 'S') {
                    initPlayerPos = {i, j};
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'B') {
                    initBoxPos = {i, j};
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'T')
                    targetPos = {i, j};
        return bfsBox(grid, initPlayerPos, initBoxPos, targetPos);
    }
};

int main(int argc, char const *argv[]) {
    auto testout = [](VCC grid) {
        cout << Solution().minPushBox(grid) << endl;
    };
    testout({{'#', '#', '#', '#', '#', '#'}, {'#', 'T', '#', '#', '#', '#'}, {'#', '.', '.', 'B', '.', '#'}, {'#', '.', '#', '#', '.', '#'}, {'#', '.', '.', '.', 'S', '#'}, {'#', '#', '#', '#', '#', '#'}});
    testout({{'#', '#', '#', '#', '#', '#'}, {'#', 'T', '#', '#', '#', '#'}, {'#', '.', '.', 'B', '.', '#'}, {'#', '#', '#', '#', '.', '#'}, {'#', '.', '.', '.', 'S', '#'}, {'#', '#', '#', '#', '#', '#'}});
    testout({{'#', '#', '#', '#', '#', '#'}, {'#', 'T', '.', '.', '#', '#'}, {'#', '.', '#', 'B', '.', '#'}, {'#', '.', '.', '.', '.', '#'}, {'#', '.', '.', '.', 'S', '#'}, {'#', '#', '#', '#', '#', '#'}});
    testout({{'#', '#', '#', '#', '#', '#', '#'}, {'#', 'S', '#', '.', 'B', 'T', '#'}, {'#', '#', '#', '#', '#', '#', '#'}});
    testout({{'#', '.', '.', '#', '#', '#', '#', '#'}, {'#', '.', '.', 'T', '#', '.', '.', '#'}, {'#', '.', '.', '.', '#', 'B', '.', '#'}, {'#', '.', '.', '.', '.', '.', '.', '#'}, {'#', '.', '.', '.', '#', '.', 'S', '#'}, {'#', '.', '.', '#', '#', '#', '#', '#'}});
    return 0;
}
