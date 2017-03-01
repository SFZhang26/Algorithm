# 304. Range Sum Query 2D - Immutable

class NumMatrix(object):
    
    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        if len(matrix)==0:
            return
        n, m = len(matrix), len(matrix[0])
        self.store = [ [0 for j in xrange(m+1)] for i in xrange(n+1) ]
        for i in xrange(1,n+1):
            for j in xrange(1,m+1):
                self.store[i][j]=matrix[i-1][j-1]+self.store[i-1][j]+self.store[i][j-1]-self.store[i-1][j-1]
        

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return self.store[row2+1][col2+1]-self.store[row2+1][col1]-self.store[row1][col2+1]+self.store[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
