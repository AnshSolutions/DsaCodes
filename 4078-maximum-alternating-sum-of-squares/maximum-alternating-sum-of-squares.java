import java.util.Vector;
class Solution {
    public long maxAlternatingSum(int[] nums) {
        Vector<Long>vec=new Vector<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            long a=nums[i];
            Long  sq=a*a;
            vec.add(sq);
        }
        Collections.sort(vec);
        int half=n/2;
        long sum=0;
        for(int i=0;i<half;i++){
                 sum+=vec.get(i);
        }
        //get full sum
        long fsum=0;
        for(int i=0;i<n;i++){
           fsum+=vec.get(i);

        }
        long restsum=fsum-sum;
        return restsum-sum;
    }
}