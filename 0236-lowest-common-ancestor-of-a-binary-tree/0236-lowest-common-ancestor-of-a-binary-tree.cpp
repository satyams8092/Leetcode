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

    bool findPath(TreeNode* root, stack<TreeNode*>& st, TreeNode* p){
        if(root==NULL) return false;
        st.push(root);
        if(root==p){
            return true;
        }
        if(findPath(root->left,st,p) || findPath(root->right,st,p)){
            return true;
        }
        st.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        findPath(root,st1,p);
        findPath(root,st2,q);

        while (st1.size() > st2.size()) st1.pop();
        while (st2.size() > st1.size()) st2.pop();

        while (st1.top() != st2.top()) {
            st1.pop();
            st2.pop();
        }
        
        return st1.top();
    }
};