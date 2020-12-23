#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /**
         * 思路: 以nums陣列中的位置做編碼, 比如nums = [1,2,3]則有8種組合可能: [], [3], [2], [2,3], ... [1,2,3]
         * 以編碼來看就是000, 001, 010, 011, ... 111
        */
        int n = nums.size();
        int p = 1<<n;//所有組合可能數
        vector<vector<int>> result(p);
        for(int i=0; i<p; i++){
            for(int j=0; j<n; j++){
                if(i>>j&1)//判斷編碼位置是否為1
                    result[i].push_back(nums[j]);
            }
        }
        return result;
    }
};