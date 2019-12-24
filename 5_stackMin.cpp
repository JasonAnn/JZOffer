/*
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））
解析：需要比普通栈多一个栈用于保存当前栈的最小值min，pop时两个栈的元素都要弹出栈顶元素
*/
class Solution {
public:
    stack<int> m_data;
    stack<int> m_min;
    void push(int value) {
        if(m_min.size() == 0 || value < m_min.top()){
            m_min.push(value);
        }
        else{
            m_min.push(m_min.top());
        }
    }
    void pop() {
        //assert(m_data.size()>0 && m_min.size()>0);
        m_data.pop();
        m_min.pop();
    }
    int top() {
        //assert(m_data.size()>0);
        m_data.top();
    }
    int min() {
        //assert(m_data.size()>0 && m_min.size()>0);
        return m_min.top();
    }
};
