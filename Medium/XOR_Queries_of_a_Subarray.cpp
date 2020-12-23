#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m = queries.size(), n = arr.size();
        vector<int> prefix(n+1, 0), result;
        //prefix(i)表示arr[0:i-1]間的累XOR運算
        for(int i=1; i<n+1; i++){
            prefix[i] = prefix[i-1] ^ arr[i-1];
        }
        for(int i=0; i<m; i++){
            //根據XOR運算性質: 因為a0^a0 = 0, 所以如果要算a1到ak間的累XOR運算則a0^a1^...^ak = C, a1^a2^...^ak = a0^C
            result.push_back(prefix[queries[i][1]+1]^prefix[queries[i][0]]);
        }
        return result;
    }
};