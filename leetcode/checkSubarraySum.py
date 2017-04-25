# 523. Continuous Subarray Sum

class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        vec=set([])
        total, save=0, 0
        for i in nums:
            total+=i
            left=total if k==0 else total%k
            if left in vec:
                return True
            vec.add(save)
            save=left
        return False
