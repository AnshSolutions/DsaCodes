class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        //  -----
        vector<int>a1,a2;
        int n=nums.size();
       a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        int last1=nums[0];
        int last2=nums[1];
        for(int i=2;i<n;i++){
             if(last1>last2){
                a1.push_back(nums[i]);
                last1=nums[i];
             }else{
                a2.push_back(nums[i]);
                last2=nums[i];
             }
        }
        //combine the array 
     
        vector<int> ans;

        for (int x : a1)
            ans.push_back(x);

        for (int x : a2)
            ans.push_back(x);

        return ans;
    }
};