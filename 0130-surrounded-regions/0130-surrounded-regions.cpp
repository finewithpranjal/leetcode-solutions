class Solution {
public:
    bool valid(int n, int m, int i, int j) {
        if(i<0 or i>=n or j<0 or j>=m)
           return false;
        return true;
    }
         int x[4] = {1,-1,0,0};
         int y[4] = {0,0,-1,1};

    void dfs(vector<vector<char>>& arr, int i, int j, int n, int m) {
         arr[i][j] = '#';
         for(int k = 0; k<4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if(valid(n, m, row, col) and arr[row][col] == 'O') {
                dfs(arr, row, col, n, m);
            }
         }
         return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int i, j;
        // First Row
        for(j = 0; j<m; j++) {
            if(board[0][j] == 'O') {
                dfs(board, 0, j, n, m);
            }
        }

        // Last Row
        for(j=0; j<m; j++) {
            if(board[n-1][j] == 'O'){
                dfs(board, n-1, j, n, m);
            }

        }

        // First Col
        for(i=0; i<n; i++) {
            if(board[i][0] == 'O'){
               dfs(board, i, 0, n, m);
            }
        }

        // Last Col
        for(i = 0; i<n; i++) {
            if(board[i][m-1] == 'O') {
                dfs(board, i, m-1, n, m);
            }
        }

        for(i = 0; i<n; i++) {
            for(j = 0; j<m; j++) {
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
        return;
        
    }
};