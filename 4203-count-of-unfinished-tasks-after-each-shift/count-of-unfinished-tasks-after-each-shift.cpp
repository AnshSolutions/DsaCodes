class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();
        vector<int> ans(m);
        vector<long long> prefix(n);
        prefix[0] = tasks[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + tasks[i];
        }
        long long total = prefix.back();
        long long curr = 0;
        for (int i = 0; i < m; i++) {
            if (curr + shifts[i] >= total) {
                ans[i] = 0;
                curr = 0;
            } else {
                curr += shifts[i];

                int idx = lower_bound(prefix.begin(), prefix.end(), curr + 1) -
                          prefix.begin();

                ans[i] = n - idx;
            }
        }
        return ans;
    }
};