class Solution {
    public int minMoves2(int[] nums) {
        //most optimised way is to get the middle elemnet of array  
        HashSet<Integer>st=new LinkedHashSet<>();
        HashMap<Integer,Integer>mp=new HashMap<>();
        int n=nums.length;
        int maxfreq=0;
        int ele=-1;
        for(int a:nums){
            // st.insert(a);
            st.add(a);
        }
        int ans=0;
    
             //get the middle index
             Arrays.sort(nums);
             int middle=(n/2);
             for(int a:nums){
                 ans+=Math.abs(nums[middle]-a);
             }
             
    //    }else{
    //          //put these elemnts in map get the max frequncy element and tarverse with map
    //          for(int i=0;i<nums.length;i++){
    //           mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
    //           if(mp.get(nums[i])>maxfreq){
    //                maxfreq=Math.max(maxfreq,mp.get(nums[i]));
    //                ele=nums[i];
    //           }

             
    //          }
    //          for(Map.Entry<Integer,Integer>entry:mp.entrySet()){
    //                if(entry.getKey()!=ele)    {
    //                      ans+=Math.abs(entry.getValue()*(entry.getKey()-ele));
    //                }
    //          }
    //    }
       return ans;

    }
}