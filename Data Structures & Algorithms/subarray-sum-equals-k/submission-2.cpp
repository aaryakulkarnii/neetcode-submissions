class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;   

        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;

            if (freq.find(sum - k) != freq.end()) {
                count += freq[sum - k];
            }

            freq[sum]++;
        }

        return count;
    }
};