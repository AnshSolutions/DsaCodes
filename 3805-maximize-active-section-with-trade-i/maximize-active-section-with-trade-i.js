/**
 * @param {string} s
 * @return {number}
 */
var maxActiveSectionsAfterTrade = function(s) {
let initialOnes = 0;

    for (let ch of s) {
        if (ch === '1') initialOnes++;
    }

    let blocks = [];
    let n = s.length;
    let i = 0;

    // Store lengths of all contiguous 0-blocks
    while (i < n) {
        if (s[i] === '0') {
            let start = i;

            while (i < n && s[i] === '0') {
                i++;
            }

            blocks.push(i - start);
        } else {
            i++;
        }
    }

    let maxPairSum = 0;

    for (let i = 1; i < blocks.length; i++) {
        maxPairSum = Math.max(maxPairSum, blocks[i] + blocks[i - 1]);
    }

    return initialOnes + maxPairSum;
};