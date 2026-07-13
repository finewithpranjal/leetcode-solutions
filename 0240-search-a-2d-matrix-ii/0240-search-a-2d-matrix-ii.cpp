class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Taking bottom left corner 
        int row = n - 1, col = 0;
        while (row >= 0 and col < m) {
            if (matrix[row][col] == target ) {
                return true;
            }
            if (matrix[row][col] > target) { // this is conditon for eleminating row 
                row --;
            }
            else {  // this is conditon for eliminating column
                col++;
            }
        }
        return false;
        
    }
};