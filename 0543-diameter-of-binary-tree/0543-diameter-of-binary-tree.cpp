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
    int findH(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=findH(root->left);
        int rh=findH(root->right);
        return 1+max(lh,rh);
    }

    void maxHeight(TreeNode* root,int& maxi){
        if(root==NULL){
            return;
        }
        int lh=findH(root->left);
        int rh=findH(root->right);
        maxi=max(maxi,lh+rh);

        maxHeight(root->left,maxi);
        maxHeight(root->right,maxi);

    } 

    int diameterOfBinaryTree(TreeNode* root) {
        int maxH=0;
        maxHeight(root,maxH);
        return maxH;
    }
};