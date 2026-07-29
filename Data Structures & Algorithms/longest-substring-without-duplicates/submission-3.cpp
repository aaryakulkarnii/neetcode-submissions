class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        
        int left=0;
        int res=0;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left]]--;
                if(mp[s[left]]==0)
                    mp.erase(s[left]);
                left++;

            }
            res=max(res,right-left+1);

        }
        return res;
    }
};