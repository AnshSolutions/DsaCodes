class Solution {
public:
    vector<int> prefixsum;
    int solve(int i, int j, vector<vector<int>>&dp) {
        if (i == j)
            return 0;
            if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        for (int k = i; k < j; k++) {
            
            int left = prefixsum[k + 1] - prefixsum[i];
            int right = prefixsum[j + 1] - prefixsum[k + 1];
            if (left < right) {
                ans = max(ans, left + solve(i, k,dp));
            } else if (left > right) {
                ans = max(ans, right + solve(k + 1, j,dp));
            } else {
                ans =
                    max(ans, max(left + solve(i, k,dp), right + solve(k + 1, j,dp)));
            }
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& stonevalue) {
        // try from every possible index
        // have prefix sum of arary and minus the last index of array
        // add the minimumvalue then araay become the partion
        int n = stonevalue.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      prefixsum.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixsum[i + 1] = prefixsum[i] + stonevalue[i];
        }
        return solve(0, n - 1,dp);
    }
};