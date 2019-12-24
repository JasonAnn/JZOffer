/*
题目：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）

解析：
遍历pop序列，维持一个元素栈，当元素栈为空或者栈顶元素不等于当前pop序列所指向的值时，将push序列的值逐个插入栈；
若元素栈栈顶元素等于pop序列当前值，则将弹出栈顶元素，并将pop指向下一位置，最后判断若栈为空且pop的挡墙位置指向pop序列的末尾，则返回true
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int pushV_size = pushV.size();
        int popV_size = popV.size();
        stack<int> m_data;
        bool res = false;
        if(pushV_size != popV_size) return res;
        
        int nextPush = 0; //push序列的当前位置
        int nextPop = 0;  //pop序列的当前位置
        for(; nextPop < popV_size; nextPop++){
            while(m_data.empty() || m_data.top() != popV[nextPop]){ //将pop序列当前位置元素在push序列中以前的所有元素插入栈内
                if(nextPush == pushV_size) break; //表明push序列没有当前需要pop的元素
                m_data.push(pushV[nextPush]);
                nextPush++;
            }
            if(m_data.top() != popV[nextPop]) break; //栈顶元素不等于待pop元素
            m_data.pop(); //栈顶元素等于待pop元素
        }
        if(m_data.empty() && nextPop == popV_size)
            res = true;
        return res;
    }
};
