# 646. Maximum Length of Pair Chain

class Solution:
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        if len(pairs) == 0:
            return 0
        pairs.sort(key=lambda x: x[1])
        res = 1
        cur_b = pairs[0][1]
        for i in range(1, len(pairs)):
            if pairs[i][0] <= cur_b:
                continue
            else:
                cur_b = pairs[i][1]
                res += 1
        return res
        
