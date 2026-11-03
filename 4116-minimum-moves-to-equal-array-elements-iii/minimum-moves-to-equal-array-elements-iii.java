class Solution {
    public int minMoves(int[] nums) {
        //get the maximu  from the array
        int maximum=Integer.MIN_VALUE;
                for(int a:nums){
            maximum=Math.max(a,maximum);
        }
        int count=0;
        for(int a:nums){
            count+=Math.abs(a-maximum);
        }
        return count;
    }
}