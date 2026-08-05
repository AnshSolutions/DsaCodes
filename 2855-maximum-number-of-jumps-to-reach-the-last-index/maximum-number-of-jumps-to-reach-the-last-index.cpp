class Solution {
public:
    int n;

    int solve(vector<int>& nums, int target, int idx,vector<int>&dp) {
        if (idx == n - 1)
            return 0;
        if(dp[idx]!=-1)return dp[idx];
        int ans = INT_MIN;

        for (int i = idx + 1; i < n; i++) {
            if (abs(nums[i] - nums[idx]) <= target) {
                int temp = solve(nums, target, i,dp);

                if (temp != INT_MIN)
                    ans = max(ans, 1 + temp);
            }
        }

        return dp[idx]=ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
vector<int>dp(n+1,-1);
        int ans = solve(nums, target, 0,dp);

        return (ans == INT_MIN) ? -1 : ans;
    }
};