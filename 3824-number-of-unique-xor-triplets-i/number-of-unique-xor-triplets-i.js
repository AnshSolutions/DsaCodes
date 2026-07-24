/**
 * @param {number[]} nums
 * @return {number}
 */
var uniqueXorTriplets = function(nums) {
    let n=nums.length;
    if(n==1 || n==2)return n;
    let ans=1;
    while(ans<=n){
        ans=ans*2;
    }
    return ans;
};