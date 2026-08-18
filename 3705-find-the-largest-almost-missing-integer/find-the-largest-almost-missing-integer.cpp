class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();
         unordered_map<int, int> mp;

       
        for (int x : nums) {
            mp[x]++;
        }
        if (k == 1) {
               int ans = -1;

            for (auto it : mp) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }

            return ans;
        } else if (k == n) {
            int b = *max_element(nums.begin(), nums.end());
            return b;
        } else {
            int first = nums[0];
            int last = nums[n - 1];

            if (mp[first] == 1 && mp[last] == 1) {
                return max(first, last);
            } else if (mp[first] == 1) {
                return first;
            } else if (mp[last] == 1) {
                return last;
            } else {
                return -1;
            }
        }
    }
};