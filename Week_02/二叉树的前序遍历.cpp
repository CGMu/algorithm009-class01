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
    // 递归实现二叉树前序遍历
    // vector<int> res;
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root){
    //         res.push_back(root->val);
    //         preorderTraversal(root->left);
    //         preorderTraversal(root->right);
    //     }
    //     return res;
    // }

    // 栈实现二叉树前序遍历
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            stack<TreeNode*> s1;
            s1.push(root);
            while(!s1.empty()){
                TreeNode* curNode=s1.top();
                s1.pop();
                res.push_back(curNode->val);
                if(curNode->right) s1.push(curNode->right);
                if(curNode->left) s1.push(curNode->left);
            }
        }
        return res;
    }
};