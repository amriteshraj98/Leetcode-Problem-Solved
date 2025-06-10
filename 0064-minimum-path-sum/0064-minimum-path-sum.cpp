class Solution {
public:

    // Top-down recursive solution with memoization (not used in main call)
    int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return INT_MAX;  // Out of bounds
        if (i == 0 && j == 0) return grid[0][0];  // Base case

        if (dp[i][j] != -1) return dp[i][j];  // Use memoized value

        return dp[i][j] = grid[i][j] + min(f(i - 1, j, dp, grid), f(i, j - 1, dp, grid));
    }

    // Bottom-up DP approach (used)
    int f2(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        // Fill first row
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Fill first column
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Uncomment to use the top-down recursive approach:
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f(m - 1, n - 1, dp, grid);

        // Use bottom-up approach
        return f2(grid, m, n);
    }
};