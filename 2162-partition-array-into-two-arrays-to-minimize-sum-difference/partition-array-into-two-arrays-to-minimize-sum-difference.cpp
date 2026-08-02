class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(); // 2*n

        int S = accumulate(begin(nums), end(nums), 0);

        int n = N / 2;

        int n1 = n; // left side
        int n2 = n; // right side

        // sumsLeft : size -> {subsetSums}
        unordered_map<int, vector<int>> sumsLeft;
        for (int mask = 0; mask < (1 << n1); mask++) {
            int s = 0; // subset sum
            int count = 0;

            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i)) {
                    s += nums[i];
                    count++;
                }
            }
            sumsLeft[count].push_back(s);
        }

        // sumsRight : size -> {subsetSums}
        unordered_map<int, vector<int>> sumsRight;
        for (int mask = 0; mask < (1 << n2); mask++) {
            int s = 0; // subset sum
            int count = 0;

            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i)) {
                    s += nums[n1 + i];
                    count++;
                }
            }
            sumsRight[count].push_back(s);
        }

        // NOTE : Sorting a bucket of size b costs O(b log b). Time Complexity -
        // O(2^n · log(2^n)) = O(n · 2^n).
        for (int count = 0; count <= n2; count++) {
            // sumsRight[count] this is my vector of subset sum having subset of
            // size count
            sort(begin(sumsRight[count]), end(sumsRight[count]));
        }

        int minValue = INT_MAX; // abs(2*s1 - S)

        for (int k = 0; k <= n1; k++) {
            int m = n - k; // left hand side me k elements hai to right hand
                           // side me n-k elements

            for (int leftSubSum : sumsLeft[k]) {
                int need = (S - 2 * leftSubSum) / 2;

                int low =
                    lower_bound(begin(sumsRight[m]), end(sumsRight[m]), need) -
                    begin(sumsRight[m]);

                if (low < sumsRight[m].size()) {
                    int rightSubSum = sumsRight[m][low];
                    minValue =
                        min(minValue, abs(2 * (leftSubSum + rightSubSum) - S));
                }

                if (low - 1 >= 0) {
                    int rightSubSum = sumsRight[m][low - 1];
                    minValue =
                        min(minValue, abs(2 * (leftSubSum + rightSubSum) - S));
                }
            }
        }

        return minValue;
    }
};