class Solution {
public:
bool solve(int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1){
        return dp[n];
    }
    for(int x=1;x*x<=n;x++){
        int square=x*x;
        if(solve(n-square,dp)==false){
             return dp[n]=true;
        }
    }
    return dp[n]=false;
}
    bool winnerSquareGame(int n) {
        //already a perfect square number -->return true

        //else pass to function on alice turn do your best means trying to find nearest square 
        //expect worst from bob
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};