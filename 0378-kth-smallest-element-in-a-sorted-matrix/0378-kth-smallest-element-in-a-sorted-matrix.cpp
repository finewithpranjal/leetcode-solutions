class Solution {
public:
    int fun(vector<vector<int>>& matrix, int n, int m, int guess) {
        int row = n - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 and col < m) {

            if (matrix[row][col] <= guess) {
                count = count + row + 1;
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        int low = matrix[0][0], high = matrix[n - 1][m - 1];
        int ans = 0;

        while (low <= high) {
            int guess = low + (high - low) / 2;
            int ans = fun(matrix, n, m, guess);
            if (ans < k){
                 low = guess + 1;
                  }
            else {
                res = guess;
                high = guess - 1;
            }
        }
           return res;
    }
};