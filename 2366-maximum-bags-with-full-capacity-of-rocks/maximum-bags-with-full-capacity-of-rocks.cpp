class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // minimum diffrence priority 
        int n=capacity.size();

        vector<int>diff(n);
        for(int i=0;i<n;i++){
             diff[i]=capacity[i]-rocks[i];
        }
        sort(diff.begin(),diff.end());
        int ans=0;
        for(auto a:diff){

             if(a<=additionalRocks){
                ans++;
                additionalRocks-=a;
             }
        }
        return ans;
    }
};