class Solution {
public:

    int solve(vector<vector<char>>& matrix,
              int i,
              int j,
              int& maxi,
              vector<vector<int>>& dp) {

        // Out of bounds
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;

        // If current cell is 0,
        // no square can start from here.
        if (matrix[i][j] == '0')
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(matrix, i, j + 1, maxi, dp);

        int diagonal = solve(matrix, i + 1, j + 1, maxi, dp);

        int bottom = solve(matrix, i + 1, j, maxi, dp);

        dp[i][j] = 1 + min({
            right,
            diagonal,
            bottom
        });

        maxi = max(maxi, dp[i][j]);

        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxi = 0;

        // Call solve for EVERY cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                solve(matrix, i, j, maxi, dp);

            }
        }

        return maxi * maxi;
    }
};