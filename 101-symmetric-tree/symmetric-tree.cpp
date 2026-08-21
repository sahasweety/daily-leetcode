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
    bool fun(TreeNode* left, TreeNode* right){
        if(left==NULL && right ==NULL)
        return true;
        if(left ==NULL || right ==NULL)
        return false;

        if(left -> val != right->val)
        return false;

        bool a = fun(left-> left , right-> right);
        bool b= fun(left -> right , right->left);

        if(a == true && b==true)
        return true;

       return false; 
    }
    bool isSymmetric(TreeNode* root) {

        if(root==NULL)
        return true;

        return fun(root -> left , root ->right);
    }
};