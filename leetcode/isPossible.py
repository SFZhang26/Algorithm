#  659. Split Array into Consecutive Subsequences

class Solution:
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        from collections import defaultdict
        count = defaultdict(lambda: 0)
        tail = defaultdict(lambda: 0)
        for i in nums:
            count[i] += 1
        for i in nums:
            if count[i] == 0:
                continue
            count[i] -= 1
            if tail[i-1] > 0:
                tail[i-1] -= 1
                tail[i] += 1
            elif count[i+1] > 0 and count[i+2] > 0:
                count[i+1] -= 1
                count[i+2] -= 1
                tail[i+2] += 1
            else:
                return False
        return True
        
