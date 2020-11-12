#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, 0);//第i項表示days[0:i]最便宜的購票價格
        for(int i=0; i<n; i++){
            if(i == 0)  dp[i] = min(costs[0], min(costs[1], costs[2]));//days[0]因為只有一天挑最便宜的票買就好(有可能月票比日票便宜 = =)
            else{
                //加入days[i]這天後看要繼續買日票, 還是要重組先前購票方式買周票或月票
                int day_pass = dp[i-1] + costs[0], week_pass = 0, month_pass = 0;
                //評估周票
                //從days[i]倒退到7天前, 看哪一天要搭車的日子最接近這天, 看該天搭車最便宜購票方式加上周票的價格
                int d = days[i] - 7 + 1;
                if(d > 0){
                    int idx = -1;
                    for(int j=i; j>=0; j--){
                        if(days[j] < d){
                            idx = j;
                            break;
                        }
                    }
                    if(idx >= 0)
                        week_pass = dp[idx] + costs[1];
                    //有可能剛好剛好7天
                    else
                        week_pass = costs[1];
                }
                //假若到目前為止不足7天, 就直接以周票價格來看
                else{
                    week_pass = costs[1];
                }
                //評估月票, 同評估周票方式
                d = days[i] - 30 + 1;
                if(d > 0){
                    int idx = -1;
                    for(int j=i; j>=0; j--){
                        if(days[j] < d){
                            idx = j;
                            break;
                        }
                    }
                    if(idx >= 0)
                        month_pass = dp[idx] + costs[2];
                    else
                        month_pass = costs[2];
                }
                else{
                    month_pass = costs[2];
                }
                //挑最便宜的購票方式
                dp[i] = min(day_pass, min(week_pass, month_pass));
            }
        }
        
        return dp[n-1];
    }
};