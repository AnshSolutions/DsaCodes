class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int minlen = INT_MAX;
        int l = 0;
        int r = 0;
        int n = s.length();
        int one = 0;
       string ans="";
        while (r < n) {
            if (s[r] == '1')
                one++;
            while (one == k) {
                 int len=r-l+1;
                 if(len<minlen){
                     minlen=len;
                     ans=s.substr(l,len);
                 }
                 else if(len==minlen){
                     ans = min(ans, s.substr(l, len));
                 }
                 if(s[l]=='1'){
                    one--;
                    
                 }
                 l++;
            }
            r++;
        }
        return ans;
       

    }
};