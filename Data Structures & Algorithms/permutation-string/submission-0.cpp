class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if (n > m) return false;

        // Sort s1
        sort(s1.begin(), s1.end());

        // Check each substring
        for (int i = 0; i <= m - n; i++) {
            string temp = s2.substr(i, n);
            sort(temp.begin(), temp.end());

            // Using find()
            if (temp.find(s1) != string::npos) {
                return true;
            }
        }
        return false;
    }
};
