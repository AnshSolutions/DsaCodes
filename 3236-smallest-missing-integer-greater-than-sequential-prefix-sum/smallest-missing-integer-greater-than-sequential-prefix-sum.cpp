class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto a:nums){
            mp[a]++;
        }
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
               
            }else{
              break;
            }

        }
        //find the smallest value neraest to sum that is not present
        while(mp.find(sum)!=mp.end()){
            sum++;
        }
        return sum;
    }
};