# 554. Brick Wall

class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        count={}
        for i in range(len(wall)):
            cur=0
            for j in range(len(wall[i])-1):
                cur+=wall[i][j]
                if cur not in count:
                    count[cur]=1
                else:
                    count[cur]+=1
        result=0
        for key in count.keys():
            result=max(result,count[key])
        return len(wall)-result                
