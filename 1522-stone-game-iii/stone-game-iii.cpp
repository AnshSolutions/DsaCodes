class Solution {
public:
    int solve(int i, int n, vector<int>& sv,  vector<int>&dp) {
        if (i >= n)
            return 0;
            if(dp[i]!=-1){
                return dp[i];
            }
        int result = INT_MIN;
        result = max(result, sv[i] - solve(i + 1, n, sv,dp));
        if (i + 1 < n)
            result = max(result, sv[i] + sv[i + 1] - solve(i + 2, n, sv,dp));
        if (i + 2 < n)
            result = max(result,
                         sv[i] + sv[i + 1] + sv[i + 2] - solve(i + 3, n, sv,dp));
        return dp[i] =result;
    }
    string stoneGameIII(vector<int>& sv) {
        int n = sv.size();
        int i = 0;
        vector<int>dp(n+1,-1);
        int diff = solve(i, n, sv,dp);
        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
       
            return "Tie";
    }
};