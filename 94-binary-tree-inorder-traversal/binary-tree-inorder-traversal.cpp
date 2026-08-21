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
    void fun(TreeNode* node, vector<int>& ans){
        if(node == NULL)
        return;

        fun(node -> left, ans);
        ans.push_back(node ->val);
        fun(node ->right, ans);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        fun(root, ans);
        return ans;
        
    }
};