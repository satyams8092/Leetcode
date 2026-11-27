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
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr=inorder(root);

        int i=0;
        int j=arr.size()-1;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==k){
                return true;
            }else if(sum>k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }

    vector<int> inorder(TreeNode* root){
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node=root;

        while(true){
            if(node){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
    }
};