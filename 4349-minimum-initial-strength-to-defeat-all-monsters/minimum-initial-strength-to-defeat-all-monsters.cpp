class Solution {
public:
typedef long long ll;
bool valid (vector<int>& monsters,vector<ll>&diff,ll st){
    int n=monsters.size();
       for(int i=0;i<n;i++){
          if(st+diff[i]<monsters[i])return false;
          st-=monsters[i];
          if(st<0)st=0;
       }
       return true;
}
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long>diff(n+1,0);
        for(auto &b:boosts){
            int l=b[0];
            int r=b[1];
            int v=b[2];
            diff[l]+=v;
            diff[r+1]-=v;
        }
        ll sum=monsters[0];
        for(int i=1;i<n;i++){
            sum+=monsters[i];
            diff[i]+=diff[i-1];
        }
        ll  l=0;
        ll h=sum;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(valid(monsters,diff,mid)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};