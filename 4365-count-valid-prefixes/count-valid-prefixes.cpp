class Solution {
public:
bool valid(string a){
    int l=a.length();
    int ones=0;
    int zero=0;
    for(auto w:a){
        if(w=='1'){
            ones++;
        }else{
            zero++;
        }
    }
    return abs(ones-zero)<=1;
}
    int countValidPrefixes(string s) {
        // every possible string from 0 
        int n=s.length();
        int ans=0;
        for(int i=1;i<=n;i++){
            string a=s.substr(0,i);
            if(valid(a)){
                ans++;
            }
        }
        return ans;
    }
};