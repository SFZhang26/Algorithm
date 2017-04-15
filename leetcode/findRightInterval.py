# 436. Find Right Interval

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        result=[]
        index={}
        self.start_li=[]
        
        for i in range(len(intervals)):
            index[intervals[i].start]=i
            self.start_li.append(intervals[i].start)
        
        self.start_li=sorted(self.start_li)
        
        for interval in intervals:
            res=self.get_index(interval.end)
            result.append(-1 if res==-1 else index[self.start_li[res]])
        return result
    
    def get_index(self, target):
        if len(self.start_li)==0:
            return -1
        left=0
        right=len(self.start_li)-1
        while left<=right:
            mid=left+int((right-left)/2)
            if self.start_li[mid]==target:
                return mid
            elif self.start_li[mid]>target:
                right=mid-1
            else:
                left=mid+1
        return -1 if left==len(self.start_li) else left
