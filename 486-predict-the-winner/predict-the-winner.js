var predictTheWinner = function(nums) {

    function solve(i, j) {
        if (i > j) return 0;
        if (i === j) return nums[i];

        // Pick the left element
        let op1 = nums[i] + Math.min(
            solve(i + 1, j - 1),
            solve(i + 2, j)
        );

        // Pick the right element
        let op2 = nums[j] + Math.min(
            solve(i, j - 2),
            solve(i + 1, j - 1)
        );

        return Math.max(op1, op2);
    }

    let totalScore = nums.reduce((sum, num) => sum + num, 0);
    let maxScore = solve(0, nums.length - 1);

    return maxScore >= Math.ceil(totalScore / 2);
};