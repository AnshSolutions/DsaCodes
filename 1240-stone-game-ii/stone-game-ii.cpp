class Solution {
public:
 int t[101][101][2];
    int solve(vector<int>& piles, int i, int m, int person) {
        int n = piles.size();
        if (i >= piles.size())
            return 0;
        if(t[i][m][person]!=-1){
            return t[i][m][person];
        }
        int stones = 0;
        int result = (person == 1) ? -1 : INT_MAX;
        for (int x = 1; x <= min(2 * m, n - i); x++) {
            stones += piles[i + x - 1];
            if (person == 1) {
                result =
                    max(result, stones + solve(piles, i + x, max(m, x), 0));
            } else {
                result = min(result, solve(piles, i + x, max(m, x), 1));
            }
        }

        return t[i][m][person]= result;
    }
    int stoneGameII(vector<int>& piles) { 
        memset(t, -1, sizeof(t));
        return solve(piles, 0, 1, 1);
         
     }
};