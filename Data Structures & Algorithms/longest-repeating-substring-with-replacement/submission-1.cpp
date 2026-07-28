class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freqs;
        int res=0,l=0,maxf=0;
        for(int r=0;r<s.size();r++){
            freqs[s[r]]++;
            maxf=max(maxf,freqs[s[r]]);
            while((r-l+1)-maxf>k){
                freqs[s[l]]--;
                l++;
                if(freqs[s[l]]==0)
                freqs.erase(l);
            }
            res=max(res,r-l+1);
        }
        return res;
        
    }
};