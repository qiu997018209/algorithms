/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
     //思路:遍历得到所有路径和，记录满足目标值的路径
    
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        int sum = 0;
        vector<int> vPath;
        
        path_sum(root,target,sum,vPath,vResult);
        return vResult;
    }
    
    //注意:sum的值代表到当前节点的为止的路径和
    void path_sum(TreeNode *root,int target,int sum,vector<int> vPath, vector<vector<int>> &vResult){
        
        //考虑二叉树就是一个NULL
        if(root == NULL){
            return;
        }
        //已经到达叶子节点
        if((root->left == NULL)&&(root->right == NULL)){
            sum = root->val + sum;
            vPath.push_back(root->val);
            if(sum == target){
                vResult.push_back(vPath);
            }
            return;
        }
        //没有到达叶子节点,记录数据,继续遍历
        sum += root->val;
        vPath.push_back(root->val);   
        path_sum(root->left,target,sum,vPath,vResult);       
        path_sum(root->right,target,sum,vPath,vResult); 
        
        return;
    }
    private:
        vector<vector<int>> vResult;
};

