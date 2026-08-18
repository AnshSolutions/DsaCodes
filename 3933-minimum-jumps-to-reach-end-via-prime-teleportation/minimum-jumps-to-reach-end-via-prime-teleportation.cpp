class Solution {
public:
    vector<bool> isPrime;

    void buildsieve(int n) {
        isPrime.assign(n + 1, true);

        if (n >= 0)
            isPrime[0] = false;

        if (n >= 1)
            isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();
        int maxl = 0;

        unordered_map<int, vector<int>> g;

        for (int i = 0; i < n; i++) {
            g[nums[i]].push_back(i);
            maxl = max(maxl, nums[i]);
        }

        buildsieve(maxl);

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        // To avoid processing the same prime again
        unordered_set<int> seen;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return steps;

                // Move to i - 1
                if (i - 1 >= 0 && !vis[i - 1]) {
                    q.push(i - 1);
                    vis[i - 1] = true;
                }

                // Move to i + 1
                if (i + 1 <= n - 1 && !vis[i + 1]) {
                    q.push(i + 1);
                    vis[i + 1] = true;
                }

                // If nums[i] is not prime
                // OR this prime has already been processed
                if (!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                /*
                    nums[i] is prime.

                    We can jump to every index whose
                    value is a multiple of nums[i].

                    Example:

                    nums[i] = 3

                    We check:
                    3, 6, 9, 12, 15, ...
                */

                for (int multiple = nums[i];
                     multiple <= maxl;
                     multiple += nums[i]) {

                    // No index having this value
                    if (!g.contains(multiple)) {
                        continue;
                    }

                    // Visit all indices having this value
                    for (int j : g[multiple]) {

                        if (!vis[j]) {
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }

                // This prime has now been processed
                seen.insert(nums[i]);
            }

            // Move to next BFS level
            steps++;
        }

        return -1;
    }
};