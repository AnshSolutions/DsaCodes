/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function(n) {
    let a= n.toString();
    let length=a.length;
    let maxmul=0;
    for(let i=0;i<length;i++){
        for(let j=i+1;j<length;j++){
            let mul=Number(a[i])*Number(a[j]);
              maxmul=Math.max(maxmul,mul);
        }
    }
    return maxmul;
};