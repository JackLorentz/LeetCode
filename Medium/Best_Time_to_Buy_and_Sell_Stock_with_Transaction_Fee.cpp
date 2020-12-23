#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /**
         * 規則: 每天可以選擇要不要交易股票, 但只能持有一張股票
         * 若不交易股票那就是跟前一天獲利相同,
         * 若交易股票就是"最大獲利" = "之前最大獲利" + "今天賣出股票的錢" - "之前最大獲利那天買股票的錢" - "手續費"
         * 所以如果要評估該天是否交易, 就是要讓"今天賣出股票的錢"以外的獲利最大化
         * max_profit: 從第0天到現在交易股票的最大獲利
         * buy_profit = "之前最大獲利" - "之前最大獲利那天買股票的錢" - "手續費"
        */
        int n = prices.size(), max_profit, buy_profit;
        for(int i=0; i<n; i++){
            //第0天沒辦法持有股票進行交易, 所以獲利為0
            if(i == 0){
                max_profit = 0;
                buy_profit = max_profit - prices[i] - fee;
            }
            else{
                max_profit = max(max_profit, prices[i] + buy_profit);
                buy_profit = max(buy_profit, max_profit - prices[i] - fee);
            }   
        }
        return max_profit;
    }
};