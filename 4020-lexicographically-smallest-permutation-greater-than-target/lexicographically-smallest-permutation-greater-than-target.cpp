class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.length();

        vector<int> cnt(26, 0);

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        string ans = "";

        // Try to construct a permutation equal to target
        // for as long as possible.
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // If target[i] is available, use it.
            if (cnt[x] > 0) {
                ans += target[i];
                cnt[x]--;
            }
            else {
                // Cannot continue equal prefix.
                // We must backtrack and make an earlier
                // position greater.
                break;
            }
        }

        // -------------------------------------------------
        // Backtrack from the current position.
        // -------------------------------------------------

        int start = min((int)ans.size(), n - 1);

        for (int i = start; i >= 0; i--) {

            // If i == ans.size(), nothing was consumed
            // at this position.
            if (i < (int)ans.size()) {
                cnt[ans[i] - 'a']++;
            }

            // Find smallest character > target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string result = ans.substr(0, i);

                    // Put a greater character here
                    result += char('a' + c);
                    cnt[c]--;

                    // Fill remaining positions with
                    // smallest possible characters.
                    for (int j = 0; j < 26; j++) {
                        while (cnt[j] > 0) {
                            result += char('a' + j);
                            cnt[j]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};