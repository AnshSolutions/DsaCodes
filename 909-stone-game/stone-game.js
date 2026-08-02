/**
 * @param {number[]} piles
 * @return {boolean}
 */
var stoneGame = function(piles) {
    let n = piles.length;
    let dp = Array.from({ length: n }, () => Array(n).fill(-1));

    function solve(i, j) {
        if (i > j) return 0;
        if (i === j) return piles[i];

        if (dp[i][j] !== -1) return dp[i][j];

        let op1 = piles[i] + Math.min(
            solve(i + 2, j),
            solve(i + 1, j - 1)
        );

        let op2 = piles[j] + Math.min(
            solve(i + 1, j - 1),
            solve(i, j - 2)
        );

        return dp[i][j] = Math.max(op1, op2);
    }

    let alex = solve(0, n - 1);

    let total = 0;
    for (let x of piles) total += x;

    return alex >= Math.ceil(total / 2);
};