#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        /**
         * 較快方法: 用Queue解
         * 先把輸入放進queue中, 接著依序將queue中每個字串中字母的大寫改成小寫
         * 小寫改成大寫, 並將結果enqueue, 這樣每個字串的每個字母都會被改到
         * */
        vector<string> result;
        int n = S.length();
        result.push_back(S);
        for(int i=0; i<n; i++){
            if(S[i] > '9'){
                int size = result.size();
                for(int j=0; j<size; j++){
                    string t(result[j]);
                    if(t[i] >= 'a')
                        t[i] = 'A' + (t[i] - 'a');
                    else
                        t[i] = 'a' + (t[i] - 'A');
                    result.push_back(t);
                }
            }   
        }
        return result;
        /**
         * 有用到位元操作的解法(慢): 
         * 先統計有幾個字母要調整, 假如有2個, 就表示有4種答案, 可以用二進位編碼表示: 00 01 10 11
         * 0表示小寫, 1表示大寫, 依序對應字串中那兩個字母可能的表示方式
        */
        /*int n = S.length(), letter_num = 0;
        vector<string> result;
        for(int i=0; i<n; i++){
            if(S[i] < '0' || S[i] > '9') letter_num++;
        }
        if(letter_num == 0){
            result.push_back(S);
            return result;
        }
        int m = int(pow(2, letter_num));
        for(int i=0; i<m; i++){
            string t = "";
            int code = i;
            for(int j=0; j<n; j++){
                if(S[j] >= '0' && S[j] <= '9')
                    t += S[j];
                else{
                    if((code & 1) == 0)
                        t += ((S[j] >= 97)? S[j] - 32 : S[j]);
                    else
                        t += ((S[j] >= 97)? S[j] : S[j] + 32);
                    code >>= 1;
                }
            }
            result.push_back(t);
        }
        return result;*/
    }
};