/*
Question:
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
A partially filled sudoku which is valid.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

//Code:
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::map<int, bool> rows[9];    //The array of map
        std::map<int, bool> colms[9];   //The array of map
        std::map<int, bool> grids[9];   //The array of map
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j] != '.') {
                    if(rows[i][board[i][j]] == false) 
                    {
                        rows[i][board[i][j]] = true;
                    } 
                    else {return false;}
                    
                    if(colms[j][board[i][j]] == false) 
                    {
                        colms[j][board[i][j]] = true;
                    } 
                    else {return false;}
                    
                    int p = i/3 * 3 + j/3;
                    if(grids[p][board[i][j]] == false) 
                    {
                        grids[p][board[i][j]] = true;
                    } 
                    else {return false;}
                }
            }
        }
        return true;
    }
};
