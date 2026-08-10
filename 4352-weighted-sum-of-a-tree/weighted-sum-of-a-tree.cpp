class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
       unordered_map<int,vector<int>>g;
       for(int i=1;i<n;i++){
         g[parent[i]].push_back(i);

       }
       queue<int>q;
       vector<int>depth(n);
       q.push(0);
       depth[0]=1;
       int height=1;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           for(auto child:g[node]){
                depth[child]=depth[node]+1;
                height=max(height,depth[child]);
                q.push(child);
           }
       }
         long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long weight =
                1LL * nums[i] * (height - depth[i] + 1);

            ans += weight;
        }

        return ans;
    }
};