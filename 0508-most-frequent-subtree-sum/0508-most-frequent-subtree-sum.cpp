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
unordered_map<int,int> freq;
int subtreesum(TreeNode *node)
{
    if(node==nullptr) return 0;

    int leftsum= subtreesum(node->left);
    int rightsum= subtreesum(node->right);

    int total = node->val+leftsum+rightsum;
    freq[total]++;
    return total;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        subtreesum(root);
        int maxf=0;
        for(auto it:freq)
        {
            if(it.second>maxf)
            maxf=it.second;
        }
        vector<int>result;
        for(auto it: freq)
        {
            if(it.second==maxf)
            result.push_back(it.first);
        }
        return result;
    }
};