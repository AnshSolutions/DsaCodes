class Solution {
public:

    int dp[101][101];

    // solve(i, M) = current player ka maximum score difference
    // (current player score - opponent score)
    int solve(vector<int>& piles, int i, int M) {

        int n = piles.size();

        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int stones = 0;
        int best = INT_MIN;

        // Current player can take 1 to 2*M piles
        for (int x = 1; x <= min(2 * M, n - i); x++) {

            stones += piles[i + x - 1];

            // I take 'stones'
            //
            // After this, opponent becomes current player.
            // solve(...) = opponent's advantage.
            //
            // So my advantage =
            // my stones - opponent's advantage

            int current =
                stones - solve(
                    piles,
                    i + x,
                    max(M, x)
                );

            // I choose the best option
            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {

        memset(dp, -1, sizeof(dp));

        int total = 0;

        for (int x : piles) {
            total += x;
        }

        // diff = Alice - Bob
        int diff = solve(piles, 0, 1);

        // Alice + Bob = total
        // Alice - Bob = diff
        //
        // Alice = (total + diff) / 2

        return (total + diff) / 2;
    }
};