# 575. Distribute Candies

class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        nums=set(candies)
        return min(len(candies)/2, len(nums))
