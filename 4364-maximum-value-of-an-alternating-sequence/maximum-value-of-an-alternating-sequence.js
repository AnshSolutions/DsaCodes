/**
 * @param {number} n
 * @param {number} s
 * @param {number} m
 * @return {number}
 */
var maximumValue = function(n, s, m) {
    let peaks1 = Math.floor(n / 2);
    let ans1 = s;

    if (peaks1 > 0) {
        ans1 = s + m + (peaks1 - 1) * (m - 1);
    }

    // Pattern 2:
    // s > valley < peak > valley ...
    let peaks2 = Math.floor((n - 1) / 2);
    let ans2 = s;

    if (peaks2 > 0) {
        ans2 = s + (m - 1) + (peaks2 - 1) * (m - 1);
    }

    return Math.max(ans1, ans2);
};