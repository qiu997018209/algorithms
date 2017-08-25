class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    Solution(){
        stNode.val = -32768;
    }
    
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        //说明root是NULL
        if((root == NULL)&&(stNode.val == -32768)){
            return NULL;
        }
        else if((root == NULL)&&(stNode.val != -32768)){
            return &stNode;
        }
        //获取最大值
        if(root->val > stNode.val){
            stNode = *root;
        }
        
        maxNode(root->left);
        maxNode(root->right);
    }
    private:
    TreeNode stNode;
};