/**
 * @param {string} s
 * @param {character} x
 * @param {character} y
 * @return {string}
 */
var rearrangeString = function(s, x, y) {
    let countX = 0;
    let countY = 0;
    let others = [];

    // Count x, y and collect all other characters
    for (const ch of s) {
        if (ch === x) {
            countX++;
        } else if (ch === y) {
            countY++;
        } else {
            others.push(ch);
        }
    }

    let ans = "";

    // Add all y's
    while (countY--) {
        ans += y;
    }

    // Add all other characters
    for (const ch of others) {
        ans += ch;
    }

    // Add all x's
    while (countX--) {
        ans += x;
    }

    return ans;
};