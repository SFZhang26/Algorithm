# 419. Battleships in a Board

class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        result=0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]=='X':
                    if (i>0 and board[i-1][j]=='X') or (j>0 and board[i][j-1]=='X'):
                        continue
                    else:
                        result+=1
        return result
