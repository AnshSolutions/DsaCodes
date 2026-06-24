function zigZagArrays(n, l, r) {
    const MOD = 1e9 + 7;
    const M = r - l + 1;

    const dp = Array.from({ length: n + 1 }, () =>
        Array.from({ length: M + 1 }, () => Array(2).fill(-1))
    );

    function solve(i, prevval, increasing) {
        if (i === n) return 1;

        const inc = increasing ? 1 : 0;

        if (dp[i][prevval][inc] !== -1) {
            return dp[i][prevval][inc];
        }

        let result = 0;

        if (increasing) {
            for (let nextval = prevval + 1; nextval <= M; nextval++) {
                result = (result + solve(i + 1, nextval, false)) % MOD;
            }
        } else {
            for (let nextval = 1; nextval < prevval; nextval++) {
                result = (result + solve(i + 1, nextval, true)) % MOD;
            }
        }

        return (dp[i][prevval][inc] = result);
    }

    let result = 0;

    for (let i = 1; i <= M; i++) {
        result = (result + solve(1, i, true)) % MOD;
        result = (result + solve(1, i, false)) % MOD;
    }

    return result;
}