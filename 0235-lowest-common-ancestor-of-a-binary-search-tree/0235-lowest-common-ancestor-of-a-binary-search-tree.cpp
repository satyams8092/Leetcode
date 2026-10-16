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
        int p_=p->val;
        int q_=q->val;
        TreeNode* node=root;
        while((p_<node->val && q_<node->val) || (p_>node->val && q_>node->val)){
            if(p_<node->val && q_<node->val){
                node=node->left;
            }else if(p_>node->val && q_>node->val){
                node=node->right;
            }

        }
        return node;
    }
};