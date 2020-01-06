/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
          10
         /   \
        6     14             ==========>  4 <--->6 <----> 8 <----> 10 <----> 12 <---->14 <----> 16
       / \    / \
      4   8  12  16
思路一：中序遍历二叉树，递归
思路二：中序遍历二叉树到一个列表 或 数组，然后更具数组重建双向链表
思路三：类似中序遍历，先递归遍历左节点，使用栈保存遍历的节点
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return pRootOfTree;
        TreeNode* head = pRootOfTree;
        TreeNode* tmp = nullptr;
        stack<TreeNode*> _stack;
        while(head || !_stack.empty()){
            if(head){
                _stack.push(head);
                head = head->left;
            }
            else{
                TreeNode* pop = _stack.top();
                _stack.pop();
                head = pop;
                if(tmp) tmp->right = head;
                pop->left = tmp;
                tmp = pop;
                head = head->right;
            }
        }
        while(tmp->left){
            tmp = tmp->left;
        }
        return tmp;
    }
};
