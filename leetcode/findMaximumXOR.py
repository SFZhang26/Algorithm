# 421. Maximum XOR of Two Numbers in an Array

class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        for i in range(32)[::-1]:
            res<<=1
            prefix={num>>i for num in nums}
            if any(res^1^j in prefix for j in prefix):
                res+=1
        return res
