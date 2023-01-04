//DFS Recursion
//O(n) Time
//O(n) Space (Technically O(h) as number of height amount of calls will be made recursively to the function.)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//Iterative BFS
//O(n) Time
//O(n) Space (Techincally O(n/2) as at max capacity final level of leaves will be stored in queue)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* curr=q.front();q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                swap(curr->left,curr->right);
            }
        }
        return root;
    }
};