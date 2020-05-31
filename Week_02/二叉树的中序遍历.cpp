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
    // 递归实现二叉树中序遍历
    // vector<int> res;
    // vector<int> inorderTraversal(TreeNode* root) {
       // if(root){
            // inorderTraversal(root->left);
            // res.push_back(root->val);
            // inorderTraversal(root->right);
        // }
        // return res;
    // }

    // 栈实现二叉树中序遍历
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root){
        if(root){
            stack<TreeNode*> s;
            while(!s.empty()||root){ // 重点关注退出条件
                if(root){
                    s.push(root);
                    root=root->left;
                }else{
                    TreeNode* curNode=s.top();
                    res.push_back(curNode->val);
                    s.pop();
                    root=curNode->right;
                }
            }
        }
        return res;
    }
};