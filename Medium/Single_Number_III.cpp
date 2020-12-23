#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /**
         * 題意: 給個數列其中只會有兩個數出現一次, 其他數均出現兩次, 找出那兩個數
         * 解法: 將所有數XOR就會得到那兩數(a, b)的XOR結果(x), 接著要想辦法把x拆成a和b
         * 透過x & (x-1)得到a和b不同的最小位元, 再利用一次XOR就可以得到一個mask針對這個最小位元
         * 最後在遍歷一次, 把這個最小位元為1的數全部XOR起來就可以得到a或b了,
         * (因為出現兩次的數會變成0, 而出現一次的數因為這是a和b不同的最小位元所以其中一個勢必會被XOR到) 
         * 只要知道a和b其中一個就可以求得另外一個數
        */
        int x = 0, a = 0;
        for(int num : nums) x ^= num;
        int mask = x ^ (x & (x-1));
        for(int num : nums)
            if(num & mask)  a ^= num;
        return {a, x^a};
    }
};