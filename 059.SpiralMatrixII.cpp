/*Question:
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example,
Given n = 3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
SP: 54
*/

/*思路:
思路一:
直接按照54的存储matrix的值。
思路二:
该题目中的数组是n*n的，所以可以利用这一特性来改变访问数组元素的方法。
*/

//Code: 
//Code 1:
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        
        int begRow = 0;
        int endRow = n - 1;
        int begCol = 0;
        int endCol = n - 1;
        int count = 1;
        while(begRow <= endRow && begCol <= endCol)
        {
            //left->right
            if(begRow <= endRow)
            {
                for(int i = begCol; i <= endCol; ++i, ++count)
                    result[begRow][i] = count;
                ++begRow;
            }
            
            //up->down
            if(begCol <= endCol)
            {
                for(int i = begRow; i <= endRow; ++i, ++count)
                    result[i][endCol] = count;
                --endCol;
            }
            
            //right->left
            if(begRow <= endRow)
            {
                for(int i = endCol; i >= begCol; --i, ++count)
                    result[endRow][i] = count;
                --endRow;
            }
            
            //down->up
            if(begCol <= endCol)
            {
                for(int i = endRow; i >= begRow; --i, ++count)
                    result[i][begCol] = count;
                ++begCol;
            }
        }
        
        return result;
    }
};

//Code 2:
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        
        for(int k = 0, num = 1, count = (n+1)/2; k < count; ++k)
        {
            int iEnd = n - k * 2;
            
            //left->right
            for(int i = 0; i < iEnd; ++i )
                result[k][k+i] = num++;
            
            //up->down    
            for(int i = 1; i < iEnd; ++i)
                result[k+i][n-k-1] = num++;
                
            //right->left
            for(int i = 1; i < iEnd; ++i) 
                result[n-k-1][n-k-i-1] = num++;
            
            //down->up
            --iEnd;
            for(int i = 1; i < iEnd; ++i)
                result[n-k-i-1][k] = num++;
        }

        return result;
    }
};

//Code 3:
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > mat(n, vector<int>(n));
        int r = 0, c = -1, x = 1;
        const int g[5] = { 0, 1, 0, -1, 0 };
        for (int b = 0, i = 0; n > 0; n -= (b ^= 1), i = (++i % 4)) {
            for (int s = 0; s < n; s++) {
                mat[r += g[i]][c += g[i+1]] = x++;
            }
        }
        return mat;
    }
};
