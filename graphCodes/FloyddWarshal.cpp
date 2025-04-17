it is used in both directed and undirected graph 
it is used to find the shortest path between all pairs of vertices in a graph
it is a dynamic programming approach
it is a 3 loop approach
in which we let take and example we have  node 0--->1
then we need to chcek every possible way (node) to recah 0--->1
and we get any shortest path from 0--->1
we will update the shortest path in the matrix
we will use a matrix to store the shortest path
// code:
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
       
        int n=dist.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==1e8||dist[k][j]==1e8)continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                }
            }
        }
    }
};
