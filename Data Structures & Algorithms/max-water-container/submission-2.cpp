class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int res=0;
        while(left<right){
            int width=right-left;
            int currarea=min(heights[left],heights[right])*width;
            res=max(res,currarea);
            if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }


        }
        return res;
    }
};
