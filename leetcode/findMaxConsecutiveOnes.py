# 485. Max Consecutive Ones

class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=0
        cur=0
        for i in nums:
            if i==0:
                cur=0
            else:
                cur+=1
                result=max(result,cur)
        return result
