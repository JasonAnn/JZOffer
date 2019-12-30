/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)

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
    void FindCore(TreeNode* root,int expectNumber){
        path.push_back(root->val);
        if(expectNumber - root->val ==0 &&
           root->left == nullptr &&
           root->right== nullptr)
        {
            result.push_back(path);
        }
        else{
            if(root->left != nullptr){
                FindCore(root->left,expectNumber - root->val);
            }
            if(root->right != nullptr){
                FindCore(root->right,expectNumber - root->val);
            }
        }
        path.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr){
            return result;
        }
        FindCore(root,expectNumber);
        return result;
    }
private:
    vector<vector<int>>result;
    vector<int>path;
};
