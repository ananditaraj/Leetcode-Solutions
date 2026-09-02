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
    pair<int,int> height(TreeNode *root)
    {
        if(root==nullptr) return {0,0};
        auto ml=height(root->left);
        auto mr=height(root->right);
        int h=1+max(ml.first,mr.first);
        int d=ml.first+mr.first;
        int ans= max(d,max(ml.second,mr.second));
        
        return {h,ans};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        auto [h,ans]=height(root);
        return ans;        
    }
};