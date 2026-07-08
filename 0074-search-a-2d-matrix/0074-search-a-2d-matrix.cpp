class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // m for rows and n for columns

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = (m * n) - 1;

        while (low <= high) {
            int guess = low + (high - low) / 2;
            int row = guess / n;
            int col = guess % n;
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        return false;
    }
};