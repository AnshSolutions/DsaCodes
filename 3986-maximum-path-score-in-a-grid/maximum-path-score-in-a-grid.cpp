class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return INT_MIN;

        cost += (grid[i][j] != 0);

        if (cost > k)
            return INT_MIN;

        if (dp[i][j][cost] != -1)
            return dp[i][j][cost];

        if (i == n - 1 && j == m - 1)
            return dp[i][j][cost] = grid[i][j];

        int right = solve(grid, k, i, j + 1, cost);
        int down  = solve(grid, k, i + 1, j, cost);

        int best = max(right, down);

        if (best == INT_MIN)
            return dp[i][j][cost] = INT_MIN;

        return dp[i][j][cost] = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n,
                  vector<vector<int>>(m,
                  vector<int>(k + 2, -1)));

        int ans = solve(grid, k, 0, 0, 0);

        return ans == INT_MIN ? -1 : ans;
    }
};