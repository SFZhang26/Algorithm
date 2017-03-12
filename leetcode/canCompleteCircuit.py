# 134. Gas Station

class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        left,total,start=0,0,0
        for i in range(len(gas)):
            left+=(gas[i]-cost[i])
            if total+gas[i]-cost[i]<0:
                total=0
                start=i+1
            else:
                total+=(gas[i]-cost[i])
        
        return -1 if left<0 else start
