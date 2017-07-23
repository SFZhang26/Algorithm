# 645. Set Mismatch

class Solution:
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        visited = [False] * (n + 1)
        a = 0
        for i in nums:
            if visited[i]:
                a = i
                break
            else:
                visited[i] = True
        return [a, int((n + 1)*n/2 - sum(nums) + a)]
