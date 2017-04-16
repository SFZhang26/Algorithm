# 452. Minimum Number of Arrows to Burst Balloons

class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if  len(points)<=1:
            return len(points)
            
        points.sort(key=lambda x:x[1])
        result=0
        
        while len(points)>0:
            index=points[0][1]
            result+=1
            while len(points)>0 and points[0][0]<=index:
                points.pop(0)
                
        return result
