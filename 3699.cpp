class Solution {
    public:
        typedef long long ll;
        const int MOD = 1e9 + 7;
    
        int N, M;
        vector<vector<vector<int>>> dp;
    
        int solve(int i, int prevval, bool increasing) {
    
            if (i == N) return 1;
    
            if (dp[i][prevval][increasing] != -1)
                return dp[i][prevval][increasing];
    
            ll result = 0;
    
            if (increasing) {
                for (int nextval = prevval + 1; nextval <= M; nextval++) {
                    result = (result + solve(i + 1, nextval, false)) % MOD;
                }
            } else {
                for (int nextval = 1; nextval < prevval; nextval++) {
                    result = (result + solve(i + 1, nextval, true)) % MOD;
                }
            }
    
            return dp[i][prevval][increasing] = result;
        }
    
        int zigZagArrays(int n, int l, int r) {
    
            N = n;
            M = r - l + 1;
    
            dp.assign(
                N + 1,
                vector<vector<int>>(
                    M + 1,
                    vector<int>(2, -1)
                )
            );
    
            ll result = 0;
    
            for (int i = 1; i <= M; i++) {
    
                result = (result + solve(1, i, true)) % MOD;
                result = (result + solve(1, i, false)) % MOD;
            }
    
            return result;
        }
    };