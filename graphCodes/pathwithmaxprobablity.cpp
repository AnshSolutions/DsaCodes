#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succ, int start, int end) {
        unordered_map<int, list<pair<int, double>>> g;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double s = succ[i];
            g[u].push_back({v, s});
            g[v].push_back({u, s});
        }

        vector<double> res(n, 0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        res[start] = 1.0;

        while (!pq.empty()) {
            auto [su, u] = pq.top();
            pq.pop();

            for (auto [v, prob] : g[u]) {
                if (res[v] < su * prob) {
                    res[v] = su * prob;
                    pq.push({res[v], v});
                }
            }
        }

        return res[end];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges(m, vector<int>(2));
        vector<double> succ(m);

        for (int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> succ[i];
        }

        int start, end;
        cin >> start >> end;

        Solution sol;
        cout << fixed << setprecision(6) << sol.maxProbability(n, edges, succ, start, end) << "\n";
    }

    return 0;
}
