class Solution {
public:
    int maximumLengthSubstring(string s) {
        // maximum length thta contains each character two times
        int i=0;
        int j=0;
        int n=s.length();
        int res=0;
       unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};