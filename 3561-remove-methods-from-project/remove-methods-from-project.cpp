class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &g, vector<bool> &vis, int source) {

        vis[source] = true;

        for (int neighbour : g[source]) {

            if (!vis[neighbour]) {
                dfs(g, vis, neighbour);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {

        unordered_map<int, vector<int>> g;
        unordered_map<int, vector<int>> p;

        for (auto a : in) {
            int s = a[0];
            int d = a[1];

            g[s].push_back(d);
            p[d].push_back(s);
        }

        vector<bool> vis(n, false);
        vector<int> ans;

        dfs(g, vis, k);

        bool flag = false;

        for (int i = 0; i < n; i++) {

            if (vis[i]) {

                vector<int> parents = p[i];

                for (int par : parents) {

                    if (!vis[par]) {
                        flag = true;
                        break;
                    }
                }

                if (flag) break;
            }
        }

        if (flag) {
            for (int i = 0; i < n; i++)
                ans.push_back(i);
        }
        else {
            for (int i = 0; i < n; i++) {
                if (!vis[i])
                    ans.push_back(i);
            }
        }

        return ans;
    }
};