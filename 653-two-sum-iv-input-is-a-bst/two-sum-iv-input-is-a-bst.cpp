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
    stack<TreeNode* > asc;
    stack<TreeNode*> desc;

    TreeNode* getsmall(){
        if (asc.empty())
        return NULL;

        TreeNode* small=asc.top();
        asc.pop();

        TreeNode* rightchild = small->right;
        while(rightchild !=NULL){
        asc.push(rightchild);
        rightchild = rightchild->left;
        }
        return small;
    }
    TreeNode* getbig(){
        if(desc.empty())
        return NULL;

        TreeNode* big = desc.top();
        desc.pop();

        TreeNode* leftchild = big->left;
        while(leftchild !=NULL){
            desc.push(leftchild);
            leftchild= leftchild->right;
        }
        return big;
    }

    bool fun(TreeNode* root, int k){
        if(root==NULL)
        return false;

        TreeNode* t = root;

        while(t!=NULL){
            asc.push(t);
            t= t->left;
        }
        t=root;

        while(t!=NULL){
            desc.push(t);
            t = t->right;
        }
        TreeNode* i = getsmall();
        TreeNode* j = getbig();

        while(i != NULL && j!=NULL && i!=j){
            int sum = i->val + j->val;

            if(sum ==k)
            return true;

            if(sum>k)
            j = getbig();
            else
            i= getsmall();
        }
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        return fun(root,k);
    }
};