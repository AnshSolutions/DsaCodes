class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>mp;
        for(auto a:nums){
            mp.insert(a);
        }
        int i=1;
        while(true){
            int a=k*i;
            if(mp.find(a)==mp.end())return a;
            else{
                i++;
            }
        }
        return 0;
    }
};