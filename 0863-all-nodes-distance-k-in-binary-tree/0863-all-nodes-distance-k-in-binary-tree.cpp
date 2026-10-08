class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                mpp[node->left] = node;   
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right] = node; 
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> visited; 
        q.push(target);
        visited.insert(target);
        int dst = 0;

        while(!q.empty() && dst < k){     
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(mpp.find(node) != mpp.end()){
                    TreeNode* par = mpp[node];
                    if(visited.find(par) == visited.end()){   
                        visited.insert(par);
                        q.push(par);
                    }
                }
               
                if(node->left && visited.find(node->left) == visited.end()){
                    visited.insert(node->left);
                    q.push(node->left);
                }
             
                if(node->right && visited.find(node->right) == visited.end()){
                    visited.insert(node->right);
                    q.push(node->right);
                }
            }
            dst++;                      
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};