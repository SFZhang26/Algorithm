# 594. Longest Harmonious Subsequence

class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        m={}
        for i in nums:
            low, high= 1, 1
            if i in m:
                low += m[i]
                high = low
            m[i]=low
            if i-1 in m:
                high+=m[i-1]
            else:
                high=0
            if i+1 in m:
                low+=m[i+1]
            else:
                low=0
            res=max([res, low, high])
        return res
            
