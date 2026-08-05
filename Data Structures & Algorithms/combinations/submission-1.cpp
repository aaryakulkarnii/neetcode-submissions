class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>comb;
        solve(n,k,1,comb);
        return res;
    }

private:
void solve(int n,int k,int i,vector<int>&comb){
    if(i>n){
        if(comb.size()==k){
            res.push_back(comb);
        }
        return;
    }
    comb.push_back(i);
    solve(n,k,i+1,comb);
    comb.pop_back();
    solve(n,k,i+1,comb);
}
};