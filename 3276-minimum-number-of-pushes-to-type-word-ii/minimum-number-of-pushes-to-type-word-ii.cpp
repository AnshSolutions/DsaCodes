class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        for (char ch : word) {
            mp[ch]++;
        }

        vector<pair<char, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(),
             [](auto &a, auto &b) {
                 return a.second > b.second;
             });

        int sizeofarray = vec.size();
        int ans = 0;

        if (sizeofarray <= 8) {
            for (auto &a : vec) {
                ans += a.second;
            }
        }
        else if (sizeofarray <= 16) {
            for (int i = 0; i < 8; i++) {
                ans += vec[i].second;
            }

            for (int i = 8; i < sizeofarray; i++) {
                ans += 2 * vec[i].second;
            }
        }
        else if (sizeofarray <= 24) {
            for (int i = 0; i < 8; i++) {
                ans += vec[i].second;
            }

            for (int i = 8; i < 16; i++) {
                ans += 2 * vec[i].second;
            }

            for (int i = 16; i < sizeofarray; i++) {
                ans += 3 * vec[i].second;
            }
        }
        else {
            for (int i = 0; i < 8; i++) {
                ans += vec[i].second;
            }

            for (int i = 8; i < 16; i++) {
                ans += 2 * vec[i].second;
            }

            for (int i = 16; i < 24; i++) {
                ans += 3 * vec[i].second;
            }

            for (int i = 24; i < sizeofarray; i++) {
                ans += 4 * vec[i].second;
            }
        }

        return ans;
    }
};