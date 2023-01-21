//Iterative BFS
//O(n) Time
//O(n) Space
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)return res;

        queue<TreeNode*> q;
        q.push(root);
        res.push_back({root->val});
        while(!q.empty()){
            vector<int> level;
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* curr = q.front();q.pop();
                if(curr->left){
                    q.push(curr->left);
                    level.push_back(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    level.push_back(curr->right->val);
                }
            }
            if(!level.empty())
                res.push_back(level);
        }
        return res;
    }
};

//Recursive
//O(n) Time
//O(n) Space
class Solution {
public:
    vector<vector<int>> res;
    void preorder(TreeNode* root, int level){
        if(!root)return;

        if(level>=res.size()){
            res.push_back({root->val});
        }else{
            res[level].push_back(root->val);
        }
        preorder(root->left,level+1);
        preorder(root->right,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        preorder(root,0);
        return res;
    }
};