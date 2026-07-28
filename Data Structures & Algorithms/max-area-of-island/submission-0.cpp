class Solution {
    int dfs(int i, int j,
            vector<vector<bool>>& visited,
            vector<vector<int>>& grid,
            int n, int m) {

        if(i < 0 || j < 0 || i >= n || j >= m ||
           visited[i][j] || grid[i][j] == 0) {
            return 0;
        }

        visited[i][j] = true;

        return 1 +
               dfs(i-1, j, visited, grid, n, m) +
               dfs(i+1, j, visited, grid, n, m) +
               dfs(i, j-1, visited, grid, n, m) +
               dfs(i, j+1, visited, grid, n, m);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !visited[i][j]) {

                    int area = dfs(i, j, visited, grid, n, m);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};