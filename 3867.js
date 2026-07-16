/**
 * @param {number[]} nums
 * @return {number}
 */
var gcdSum = function (nums) {
    //construct mxi----------->maximum till i(including)
    //construct prefixgcd---------->gcd(nums[i],mxi)
    function gcd(a, b) {
        while (b !== 0) {
            let temp = b;
            b = a % b;
            a = temp;
        }
        return Math.abs(a); // Handles negative numbers as well
    }
    let mxi = [];
    let n = nums.length;

    mxi[0] = nums[0];

    for (let i = 1; i < n; i++) {
        if (mxi[mxi.length - 1] > nums[i]) {
            mxi.push(mxi[mxi.length - 1]);
        } else {
            mxi.push(nums[i]);
        }
    }
    let prefixGcd = [];
    for (let i = 0; i < n; i++) {
        prefixGcd[i] = gcd(nums[i], mxi[i]);
    }
    prefixGcd.sort((a, b) => a - b);
    let ans = 0;

    let left = 0;
    let right = prefixGcd.length - 1;

    while (left < right) {
        ans += gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }

    return ans;

};