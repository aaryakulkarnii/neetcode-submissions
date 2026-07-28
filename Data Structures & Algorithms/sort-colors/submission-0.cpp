class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c0 = 0, c1 = 0, c2 = 0;

        // Count occurrences of 0, 1, and 2
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) c0++;
            else if (nums[i] == 1) c1++;
            else c2++;
        }

        // Overwrite the array
        int idx = 0;

        for (int i = 0; i < c0; i++)   // ✅ should be c0, not c1
            nums[idx++] = 0;

        for (int i = 0; i < c1; i++)
            nums[idx++] = 1;

        for (int i = 0; i < c2; i++)
            nums[idx++] = 2;
    }
};
