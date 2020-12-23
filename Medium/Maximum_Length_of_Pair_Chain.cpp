#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;    
    }
    /*static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];    
    }*/
    
    int findLongestChain(vector<vector<int>>& pairs) {
        /**
         * 最快方法: 先按照每對數據(a,b)的b做遞增排序, 這樣一來接下來的遍歷只要比較該對的a和前一對的b, 如果滿足條件計數累加即可
         * 這樣排序是為了確保全部資料大小是按照遞增排序, 其中第一對數據是全部數據中最小的, 因為b都最小了, a又必小於b, 而第二對數據為第二小以此類推 
         * 這樣遍歷收集最長鏈就不用考慮這資料是接在鏈的哪一端(必接在後端)
         * (如果不用pair而用vector速度會超慢) 
        */
        int n = pairs.size(), len = 1;
        pair<int, int> chain[n];
        for(int i=0; i<n; i++){
            chain[i] = make_pair(pairs[i][0], pairs[i][1]);
        }
        sort(chain, chain+n, cmp);
        pair<int, int> tmp = chain[0];
        for(int i=1; i<n; i++){
            if(chain[i].first > tmp.second){
                len++;
                tmp.first = chain[i].first;
                tmp.second = chain[i].second;
            }
        }
        return len;
        /**
         * 傳統DP法: 將數據(a,b)以a做遞增排序, 設dp(i)表示pairs中第i個位置鏈的最大長度並遍歷收集最長鏈,
         * 因為無法確保這資料是接在鏈的哪一端, 所以每看到新的數據, 就要考慮可以接在哪個位置, 所以就要從第1筆檢查到第i-1筆
        */
        /**
        int n = pairs.size();
        int dp[n];
        memset(dp, 0, sizeof(n));
        sort(pairs.begin(), pairs.end(), cmp);
        for(int i=0; i<n; i++){
            if(i == 0)  dp[i] = 1;
            else{
                dp[i] = dp[i-1];
                for(int j=0; j<i; j++){
                    if(pairs[i][0] > pairs[j][1])
                        dp[i] = max(dp[i-1], dp[j]+1);
                }
            }
        }
        return dp[n-1];
        */
        
    }
};