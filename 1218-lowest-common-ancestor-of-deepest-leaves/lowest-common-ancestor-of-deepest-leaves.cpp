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
    pair<int,TreeNode*> fun(TreeNode* root){
        if(root == NULL)
        return { 0, NULL};
        pair<int,TreeNode*>left = fun(root ->left);
        pair<int,TreeNode*> right = fun(root->right);

        if(left.first > right.first)
        return {left.first+1, left.second }; 

        if(right.first > left.first)
        return{ right.first+1, right.second};

        return {left.first+1, root};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return fun(root).second;
        
    }
};