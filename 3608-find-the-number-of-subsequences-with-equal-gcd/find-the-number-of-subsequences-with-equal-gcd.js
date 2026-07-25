/**
 * @param {number[]} nums
 * @return {number}
 */
var subsequencePairCount = function(nums) {

    const MOD = 1000000007;
    const n = nums.length;

    function gcd(a, b) {
        while (b !== 0) {
            let temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    let maxVal = Math.max(...nums);

    // dp[index][gcd1][gcd2]
    let dp = Array.from({ length: n + 1 }, () =>
        Array.from({ length: maxVal + 1 }, () =>
            Array(maxVal + 1).fill(-1)
        )
    );

    function solve(current, currgcd1, currgcd2) {

        if (current === n) {
            if (currgcd1 !== 0 &&
                currgcd2 !== 0 &&
                currgcd1 === currgcd2)
                return 1;

            return 0;
        }

        if (dp[current][currgcd1][currgcd2] !== -1)
            return dp[current][currgcd1][currgcd2];

        // Skip
        let skip = solve(current + 1, currgcd1, currgcd2);

        // Put in seq1
        let seq1 = solve(
            current + 1,
            gcd(currgcd1, nums[current]),
            currgcd2
        );

        // Put in seq2
        let seq2 = solve(
            current + 1,
            currgcd1,
            gcd(currgcd2, nums[current])
        );

        return dp[current][currgcd1][currgcd2] =
            (((skip + seq1) % MOD) + seq2) % MOD;
    }

    return solve(0, 0, 0);
};