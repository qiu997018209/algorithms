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
    /*
     * @param root: a TreeNode, the root of the binary tree
     * @return: 
     */
     //题目介绍:将一棵二叉树按照前序遍历拆解成为一个假链表。所谓的假链表是说，用二叉树的 right 指针，来表示链表中的 next 指针。
     //不要忘记将左儿子标记为 null，否则你可能会得到空间溢出或是时间溢出。
     //注意:难点在于不使用额外的空间耗费，否则会空间溢出
    void flatten(TreeNode * root) {
        // write your code here
        //核心思想:将根节点的右子树,合入到左子树的最后一个节点的右子节点下。
        if(root == NULL){
            return;
        }
        
        //记录当前节点的根节点,左右节点
        TreeNode *temp = root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        //找到左节点子树的最后一个右节点
        //如果左节点本身已经是NULL,则无需处理了
        if(left != NULL){
            temp = left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            //将根节点的右节点,挂在temp下
            temp->right = right;
            //将根节点的左节点挂在根节点的右节点下，然后将左节点置空
            //root->right已经被挂载在root->left下
            root->right = root->left;
            root->left = NULL;
        }
        //只需要递归右节点
        flatten(root->right);         
    }
};