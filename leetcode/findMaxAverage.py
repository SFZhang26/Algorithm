# 643. Maximum Average Subarray I

class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        total = sum(nums[:k])
        res = float(total)/k
        for i in range(k, len(nums)):
            total += (nums[i]-nums[i-k])
            res = max(res, float(total)/k)
        return res
