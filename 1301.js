/**
 * @param {character[][]} board
 * @return {number[]}
 */
var pathsWithMaxScore = function(board) {

    const n = board.length;
    const MOD = 1000000007;

    // Memoization table
    const dp = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => null)
    );

    function getIntFromChar(ch) {
        return ch !== 'S' ? Number(ch) : 0;
    }

    function isValid(i, j) {
        return i >= 0 &&
               i < n &&
               j >= 0 &&
               j < n &&
               board[i][j] !== 'X';
    }

    function solve(i, j) {

        // Reached End
        if (board[i][j] === 'E')
            return [0, 1];

        // Dead End
        if (board[i][j] === 'X')
            return [0, 0];

        // Already computed
        if (dp[i][j] !== null)
            return dp[i][j];

        let upScore = 0, upPaths = 0;
        let leftScore = 0, leftPaths = 0;
        let diagScore = 0, diagPaths = 0;

        const ch = board[i][j];

        // Move Up
        if (isValid(i - 1, j)) {

            let [score, paths] = solve(i - 1, j);

            upScore = score;
            upPaths = paths;

            if (upPaths > 0)
                upScore += getIntFromChar(ch);
        }

        // Move Left
        if (isValid(i, j - 1)) {

            let [score, paths] = solve(i, j - 1);

            leftScore = score;
            leftPaths = paths;

            if (leftPaths > 0)
                leftScore += getIntFromChar(ch);
        }

        // Move Diagonal
        if (isValid(i - 1, j - 1)) {

            let [score, paths] = solve(i - 1, j - 1);

            diagScore = score;
            diagPaths = paths;

            if (diagPaths > 0)
                diagScore += getIntFromChar(ch);
        }

        let bestScore, bestPaths;

        if (upScore === leftScore && leftScore === diagScore) {

            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;

        } else if (upScore === leftScore) {

            bestScore = upScore;
            bestPaths = upPaths + leftPaths;

            if (diagScore > bestScore || (diagScore === bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore;
                bestPaths = diagPaths;
            }

        } else if (leftScore === diagScore) {

            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;

            if (upScore > bestScore || (upScore === bestScore && upPaths > bestPaths)) {
                bestScore = upScore;
                bestPaths = upPaths;
            }

        } else {

            bestScore = upScore;
            bestPaths = upPaths;

            if (leftScore > bestScore || (leftScore === bestScore && leftPaths > bestPaths)) {
                bestScore = leftScore;
                bestPaths = leftPaths;
            }

            if (diagScore > bestScore || (diagScore === bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore;
                bestPaths = diagPaths;
            }
        }

        dp[i][j] = [bestScore, bestPaths % MOD];

        return dp[i][j];
    }

    const result = solve(n - 1, n - 1);

    return [result[0], result[1]];
};