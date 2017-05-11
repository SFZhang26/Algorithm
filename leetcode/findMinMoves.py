# 517. Super Washing Machines

class Solution(object):
    def findMinMoves(self, machines):
        """
        :type machines: List[int]
        :rtype: int
        """
        if len(machines)<=1:
            return 0
        total=sum(machines)
        if total%len(machines)!=0:
            return -1
        left=0
        result=0
        target=total/len(machines)
        for num in machines:
            right=num-target-left
            result=max([result,left,right,left+right])
            left=-right
            
        return result
