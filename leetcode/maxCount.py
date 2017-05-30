# 598. Range Addition II

class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        a, b=m, n
        for vec in ops:
            a=min(a, vec[0])
            b=min(b, vec[1])
        return a*b
