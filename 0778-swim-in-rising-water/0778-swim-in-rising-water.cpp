class Solution {
public:
    bool valid(int r, int c, int n, int m) {
        if(r < 0 or r >= n or c < 0 or c >=m) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        
        // For all four direction
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        int id = grid[0][0];
        pq.push({id , {0,0}});
        res[0][0] = grid[0][0];

        while(!pq.empty()) 
        {
            pair<int, pair<int, int>>p = pq.top();
            pq.pop();
            int money = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if(money > res[row][col]) continue;
            // Visting to neighbours 

            for(int k = 0; k<4; k++) {
                int r = row + x[k];
                int c = col + y[k];

                if(!valid(r, c, n, m)) continue;
                int new_money = max(money, grid[r][c] );
                if(new_money < res[r][c]) {
                    res[r][c] = new_money;
                    pq.push({new_money, {r,c}});
                }
            }
        }
        return {res[n - 1][m - 1]};
    }
};