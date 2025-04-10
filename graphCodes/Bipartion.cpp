#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // odd length cycle not barprtrite
    bool check(vector<vector<int>>& graph, int currc, int node,
               vector<int>& color) {
        color[node] = currc;
        for (auto& v : graph[node]) {
            if (color[v] == currc) {
                return false;
            }
            if (color[v] == -1) {
                int cv = 1 - currc;
                if (check(graph, cv, v, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (check(graph, 1, i, color)) {
                    return true;
                }
            }
        }
        return false;
    }
};