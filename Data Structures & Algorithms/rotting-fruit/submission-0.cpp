#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Count fresh oranges and push rotten oranges into queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;

        int minutes = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < rows &&
                        ny >= 0 && ny < cols &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        rottedThisMinute = true;
                    }
                }
            }

            if (rottedThisMinute)
                minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};