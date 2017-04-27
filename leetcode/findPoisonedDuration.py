# 495. Teemo Attacking

class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        result=0
        timeSeries.append(100000000)
        for i in range(len(timeSeries)-1):
            result+=min(duration, (timeSeries[i+1]-timeSeries[i]))
        return result
