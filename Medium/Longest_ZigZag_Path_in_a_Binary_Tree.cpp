#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int max_len = 0;
public: 
    int longestZigZag(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        dfs(root->left, 1, 'l');//因為zigzag要成立至少有一個左和一個右, 所以起始值為1(若連左右都沒有, 那勢必只有一個節點)
        dfs(root->right, 1, 'r');
        return max_len;
    }
private:
    //d: 該節點為左子點或右子點
    void dfs(TreeNode* cur, int len, char d){
        if(!cur)    return;
        if(len > max_len)   max_len = len;//用max函數浪費記憶體
        if(d == 'l'){
            dfs(cur->left, 1, 'l');//如果左子點走其左子點, zigzag長度重置
            dfs(cur->right, len+1, 'r');//如果左子點走其右子點, zigzag長度+1
        }
        else{
            dfs(cur->left, len+1, 'l');
            dfs(cur->right, 1, 'r');
        }
    }
};