class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for (int c : nums) {
            st.insert(c);
        }

        int res = 0;

        for (int c : nums) {

            if (st.find(c - 1) == st.end()) {

                int len = 1;
                int curr = c;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }

                res = max(res, len);
            }
        }

        return res;
    }
};