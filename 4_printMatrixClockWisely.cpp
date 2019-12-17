/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

分析:
简单来说，就是不断地收缩矩阵的边界
定义四个变量代表范围，up、down、left、right
    向右走存入整行的值，当存入后，该行再也不会被遍历，代表上边界的 up 加一，同时判断是否和代表下边界的 down 交错
    向下走存入整列的值，当存入后，该列再也不会被遍历，代表右边界的 right 减一，同时判断是否和代表左边界的 left 交错
    向左走存入整行的值，当存入后，该行再也不会被遍历，代表下边界的 down 减一，同时判断是否和代表上边界的 up 交错
    向上走存入整列的值，当存入后，该列再也不会被遍历，代表左边界的 left 加一，同时判断是否和代表右边界的 right 交错 
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> list;
        if(matrix.empty()) return list;
        int up = 0;
        int down = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        int left = 0;
        while(true){
            //从左到右
            for(int col = left; col<= right; col++)
            {
                list.push_back(matrix[up][col]);
            }
            up++;
            if(up > down) break;
            //从上到下
            for(int row = up; row <= down; row++)
            {
                list.push_back(matrix[row][right]);
            }
            right--;
            if(right < left) break;
            //从右到左
            for(int col = right; col>= left; col--)
             {
                    list.push_back(matrix[down][col]);
             }
            down--;
            if(down < up) break;
            //从下到上
             for(int row = down; row >= up; row--)
             {
                    list.push_back(matrix[row][left]);
             }
            left++;
            if(left > right) break;
        }
        return list;
    }
};
