class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), max_num = -1;
        vector<int> dp(n, 0);//表示每一個長度的最大總和
        for(int i=0; i<k; i++){
            max_num = max(max_num, arr[i]);
            dp[i] = (i+1)*max_num;
        }
        for(int i=k; i<n; i++){
            max_num = arr[i];
            //從每一個子陣列的尾巴倒回去推算所有可能並比較
            for(int len=1; len<=k; len++){
                max_num = max(max_num, arr[i-len+1]);
                dp[i] = max(dp[i], max_num*len+dp[i-len]);
            }
        }
        return dp[n-1];
    }
};