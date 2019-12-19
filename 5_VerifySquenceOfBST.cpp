/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
解析：先找到输的根节点（序列最后一位），递归地判断树的左子树（从头开始比根节点小的几位），和右子树（从左子树序列末尾到根节点前一位）；像这类操作的
数据结构为vector的子序列时，可以设置开始(start）和结束（last）两个信号进行限制；
*/
class Solution {
public:
    bool VerifyCore(vector<int> sequence,int start, int last){
        int root = sequence[last];
        int i = start;
        for(;i < last; i++)
        {
            if(sequence[i] > root) break;
        }
        int j = i;
        for(;j < last; j++)
        {
            if(sequence[j]< root) return false;
        }
        bool left = true;
        if(i > 0){
            left = VerifyCore(sequence,start, i-1);
        }
        bool right = true;
        if(j < last){
            right =  VerifyCore(sequence,i,last - 1);
        }
        return left && right;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if(length == 0) return false;
        return VerifyCore(sequence,0, length-1);
    }
};
