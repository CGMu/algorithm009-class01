/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;   //若当前为空或者匹配，则返回自身
        TreeNode* left = lowestCommonAncestor(root->left, p, q);        //左子树
        TreeNode* right = lowestCommonAncestor(root->right, p, q);      //右子树
        if(!left) return right;                                         
        if(!right) return left;
        return root;                 //左右均匹配到，则答案为当前root
    }
};