#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size(), sum = 0;//表示目前有幾個Arithmetic數列
        vector<int> dp(size, 0);//dp(i)表示A[i],A[i-1],A[i-2]符合Arithmetic數列
        for(int i=2; i<size; i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                dp[i] = 1;
                //假如dp[i-1]不符合Arithmetic數列,則整體只增加1個Arithmetic數列
                //反之,跟A[i]相連的Arithmetic數列都可再延伸出1個Arithmetic數列
                (dp[i-1] == 1)? sum += i-1 : sum++;
            }
        }
        return sum;
    }
};