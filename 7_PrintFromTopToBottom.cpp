/*
题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
解析：利用队列queue作为辅助手段，初始胡时先将树的根节点加入队列，然后每次从队列弹出第一个元素后，将该元素节点的左右子节点加入队列尾部
*/

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> queueTree;
        queueTree.push(root);
        while(queueTree.size()){
            TreeNode* pNode = queueTree.front();
            result.push_back(pNode->val);
            if(pNode->left){
                queueTree.push(pNode->left);
            }
            if(pNode->right){
                queueTree.push(pNode->right);
            }
            queueTree.pop();
        }
        return result;
    }
};
