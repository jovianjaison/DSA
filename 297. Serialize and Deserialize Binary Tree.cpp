//DFS-Preorder
//O(N) Time 
//O(N) Space
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "!";
        }

        return to_string(root->val)+"#"+serialize(root->left)+"#"+serialize(root->right);
    }

    int helper(string& data){
        int pos=data.find('#');
        int val=stoi(data.substr(0,pos));
        data=data.substr(pos+1);
        return val;
    }
    TreeNode* mydeserialize(string& data) {
        //cout<<data<<"\n";
        if(data[0]=='!'){
            if(data.size()>1)data=data.substr(2);
            return NULL;
        }else{
            TreeNode* node = new TreeNode(helper(data));
            node->left=mydeserialize(data);
            node->right=mydeserialize(data);
            return node;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
};