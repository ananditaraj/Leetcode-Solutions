/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *root)
    {
        if(root==nullptr)
        return 0;
        int ml=height(root->left);
        int mr=height(root->right);
         if(ml==-1||mr==-1) return -1;
         if(abs(ml-mr)>1)
         return -1;

         return 1+max(ml,mr);
             }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        return height(root)==-1?false:true;
         
    }
};