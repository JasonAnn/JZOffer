//题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//简析：分两步走，先遍历A树找到与B树根节点的值相等的节点，再递归判断该节点的左、右节点分别与B中对应节点的左右子节点是否相等。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool Equal(double num1,double num2){
        if ((num1 - num2 > -0.0000001) && (num1 - num2 <0.0000001))
            return true;
        else return false;
    }
    
    bool DoesTree1HaveTree2(TreeNode* pRoot1,TreeNode* pRoot2){
        if(!pRoot2) return true;
        if(!pRoot1) return false;
        if(!Equal(pRoot1->val,pRoot2->val)) return false;
        return (DoesTree1HaveTree2(pRoot1->left,pRoot2->left) && DoesTree1HaveTree2(pRoot1->right,pRoot2->right));
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1 && pRoot2){
            if(Equal(pRoot1->val,pRoot2->val))
                result = DoesTree1HaveTree2(pRoot1,pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left,pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right,pRoot2);
        }
        return result;
    }
    
};
