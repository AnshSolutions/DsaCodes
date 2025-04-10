// mst=subgraph connected by edges with minimum weight
// all vertices of g and v-1 edges
// weight of mst is minimum
//no cycle 
//to find mst we can use kruskal's or prim's algorithm
//Prims algorithm
// which ds to use ->minheap (beacuse to recah a node we have diffrent way but ,we will chose with
// minimum weight){weight,node,parent}
// and a visited array
//and a parenta array with -1
typedef pair<int, int> P;

class Solution {
public:
    int minMST(unordered_map<int, list<P>> mp, int V) {
        priority_queue<P, vector<P>, greater<P>> pq;
        //  {weight,node}
        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (inMST[node])
                continue;

            inMST[node] = true;
            sum += wt;

            for (auto& [neighbor, cost] : mp[node]) {
                if (!inMST[neighbor]) {
                    pq.push({cost, neighbor});
                }
            }
        }

        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        unordered_map<int, list<P>> mp;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                mp[i].push_back({j, d});
                mp[j].push_back({i, d});
            }
        }
        return minMST(mp, V);
    }
};