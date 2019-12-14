/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

解析：可以理解为判断两棵树是否是对称树；
方法一是先判断根节点的左右节点是否相等；若相等，则分别将左右子树看作两棵树，递归判断左子树
根节点的右子节点与右子树根节点的左子节点以及左子树的根节点的左子节点与右子树根节点的右子节点是否相等；
方法二是将该树同时遍历两次，一次是先遍历左子节点，另一次是先遍历右子节点，判断每次遍历的节点是否相等，然后递归下去
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool SymmetricalCore(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot1 && !pRoot2) return true;
        if(!pRoot1 || !pRoot2) return false;
        if(pRoot1->val != pRoot2->val) return false;
        return SymmetricalCore(pRoot1->left,pRoot2->right)&&SymmetricalCore(pRoot1->right,pRoot2->left);
        
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        return SymmetricalCore(pRoot, pRoot);
    }

};
