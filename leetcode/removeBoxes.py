# 546. Remove Boxes

class Solution(object):
    def removeBoxes(self, boxes):
        """
        :type boxes: List[int]
        :rtype: int
        """
        if len(boxes)==0:
            return 0
        
        dp = [[[0]*len(boxes) for _ in boxes] for _ in boxes]
        return self.solve(boxes, dp, 0, len(boxes)-1, 0)
        
    def solve(self, boxes, dp, i, j, k):
        if i>j:
            return 0
        if dp[i][j][k]!=0:
            return dp[i][j][k]
        if i==j:
            return (k+1)*(k+1)
        while i<j and boxes[j]==boxes[j-1]:
            j-=1
            k+=1
        dp[i][j][k]=self.solve(boxes, dp, i, j-1, 0)+(k+1)*(k+1)
        for m in range(i,j):
            if boxes[j]==boxes[m]:
                dp[i][j][k]=max(dp[i][j][k], self.solve(boxes, dp, i, m, k+1)+self.solve(boxes, dp, m+1, j-1, 0))
        return dp[i][j][k]
