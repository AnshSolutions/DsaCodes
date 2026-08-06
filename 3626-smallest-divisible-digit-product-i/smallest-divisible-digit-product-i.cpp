class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
         string s=   to_string(i);
            int ans=1;
            for(int j=0;j<s.length();j++){
                ans*=s[j] - '0';
            }
            if(ans%t==0){
                return i;
            }
        }
        return 0;
    }
};