#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string sg, string eg, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        unordered_set<string> vis;
        vis.insert(sg);
        queue<string> q;
        q.push(sg);
        int l = 0;
        while (!q.empty()) {
            int sz = q.size(); // can be multiple strings at the same level
            while (sz--) {
                string s = q.front();
                q.pop();
                if (s == eg)
                    return l;
                for (char ch : "ACGT") {
                    for (int i = 0; i < s.length(); i++) {
                        string n = s;
                        n[i] = ch;
                        if (vis.find(n) == vis.end() && st.find(n) != st.end()) {
                            q.push(n);
                            vis.insert(n);
                        }
                    }
                }
            }
            l++;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        string sg, eg;
        int n;
        cin >> sg >> eg >> n;
        vector<string> bank(n);
        for (int i = 0; i < n; i++) {
            cin >> bank[i];
        }
        
        Solution sol;
        cout << sol.minMutation(sg, eg, bank) << "\n";
    }
    
    return 0;
}
