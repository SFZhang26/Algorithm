# 492. Construct the Rectangle

class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        for i in range(1,int(math.sqrt(area))+1)[::-1]:
            if area%i==0:
                return [area/i,i]
