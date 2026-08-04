class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
          sort(nums.begin(), nums.end());

        set<int> st;
        for (int x : nums) {
            st.insert(x);
        }

        int smallest = nums.front();
        int largest = nums.back();

        vector<int> ans;

        for (int i = smallest; i <= largest; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};