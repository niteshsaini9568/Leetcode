class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
      
        auto isMagicSquare = [&](int row, int col) -> int {
            if (row + 3 > rows || col + 3 > cols) {
                return 0;
            }
          
            vector<int> frequency(16, 0);
            vector<int> rowSums(3, 0);
            vector<int> colSums(3, 0);

            int mainDiagonalSum = 0;
            // Sum of anti-diagonal (top-right to bottom-left)
            int antiDiagonalSum = 0;
          
            // Iterate through the 3x3 subgrid
            for (int i = row; i < row + 3; ++i) {
                for (int j = col; j < col + 3; ++j) {
                    int value = grid[i][j];
                  
                    // Check if value is between 1 and 9, and appears only once
                    if (value < 1 || value > 9 || ++frequency[value] > 1) {
                        return 0;
                    }
                  
                    // Add value to corresponding row sum
                    rowSums[i - row] += value;
                    // Add value to corresponding column sum
                    colSums[j - col] += value;
                  
                    // Check if on main diagonal
                    if (i - row == j - col) {
                        mainDiagonalSum += value;
                    }
                  
                    // Check if on anti-diagonal
                    if (i - row + j - col == 2) {
                        antiDiagonalSum += value;
                    }
                }
            }
          
            // Check if both diagonals have the same sum
            if (mainDiagonalSum != antiDiagonalSum) {
                return 0;
            }
          
            // Check if all rows and columns have the same sum as the diagonals
            for (int k = 0; k < 3; ++k) {
                if (rowSums[k] != mainDiagonalSum || colSums[k] != mainDiagonalSum) {
                    return 0;
                }
            }
          
            // Valid magic square found
            return 1;
        };
      
        // Check every possible 3x3 subgrid in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                count += isMagicSquare(i, j);
            }
        }
      
        return count;
    }
};