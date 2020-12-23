#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int num = books.size();
        vector<int> dp(num, 0);//dp(i)表示books[i:]的最小高度
        //倒過來找是因為找最小高度差就好, 不用考慮底層放進書櫃的書
        for(int i=num-1; i>=0; i--){
            //第一本書就直接採用其高度與寬度
            if(i == num-1){
                dp[i] = books[i][1];
            }
            //第二本書之後
            else{
                int tmp_w = books[i][0], tmp_h = books[i][1];
                //最差的狀況就是直接加一層放上去
                dp[i] = dp[i+1] + books[i][1];
                //試著將第i本之後的書與第i本書放在同一層並與最差狀況比較誰高度比較小
                for(int j=i+1; j<num; j++){
                    //前提是單層總寬度符合限制
                    tmp_w += books[j][0];
                    if(tmp_w <= shelf_width){
                        //放第i本書那層的高度
                        tmp_h = max(books[j][1], tmp_h);
                        if(j < num-1)
                            dp[i] = min(dp[i], dp[j+1] + tmp_h);
                        //如果全部書都可以集中在那層, 就不用看後面那幾層的總高度
                        else
                            dp[i] = min(dp[i], tmp_h);
                    }
                    else
                        break;
                }
            }
        }
        
        return dp[0];
    }
};