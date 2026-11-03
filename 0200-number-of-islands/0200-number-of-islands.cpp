class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        if (i < 0 or i >= n or j < 0 or j >= m)
            return false;
        return true;
    }
    void explore(vector<vector<char>>& arr, int i, int j, int n,
    int m, vector<vector<bool>> &visited ) {
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};
        visited[i][j] = true;
        for(int k = 0; k<4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if(valid(row,col,n,m) and arr[row][col] == '1' and visited[row][col] == false ) {
                explore(arr, row, col, n, m, visited);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();    // size of row.
        int m = grid[0].size(); // size of col.
        int res = 0;
        int i, j;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == '1' and visited[i][j] == false) {
                  explore(grid, i, j, n, m, visited);
                  res++;
                }
            }
        }
        return res;
    }
};