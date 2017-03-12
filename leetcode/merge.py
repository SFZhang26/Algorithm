# 56. Merge Intervals

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        
        result=[]
        for i in sorted(intervals, key=lambda i:i.start ):
            if len(result)==0 or result[-1].end<i.start:
                result.append(i)
            else:
                result[-1].end=max(result[-1].end,i.end)
        
        return result
