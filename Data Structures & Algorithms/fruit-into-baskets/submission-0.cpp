#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>basket;
        int low=0;
        int res=0;
        for(int high=0;high<n;high++){
            basket[fruits[high]]++;
            while(basket.size()>2){
                basket[fruits[low]]--;;
                if(basket[fruits[low]]==0)
                basket.erase(fruits[low]);
                low++;

            }
            res=max(res,high-low+1);
        }
        return res;
    }
};