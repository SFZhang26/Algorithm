# 36. Valid Sudoku

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(9):
            l1,l2,l3=[],[],[]
            for j in range(9):
                if board[i][j]!='.':
                    if board[i][j] in l1:
                        return False
                    else:
                        l1.append(board[i][j])
                
                if board[j][i]!='.':
                    if board[j][i] in l2:
                        return False
                    else:
                        l2.append(board[j][i])
                
                if board[(i/3)*3+(j/3)][(i%3)*3+j%3]!='.':
                    if board[(i/3)*3+(j/3)][(i%3)*3+j%3] in l3:
                        return False
                    else:
                        l3.append(board[(i/3)*3+(j/3)][(i%3)*3+j%3])
        return True