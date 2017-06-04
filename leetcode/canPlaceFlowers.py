# 605. Can Place Flowers

class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        num=0
        flowerbed=[0]+flowerbed+[0]
        for i in range(1,len(flowerbed)-1):
            if flowerbed[i]==1:
                continue
            if flowerbed[i-1]==0 and flowerbed[i+1]==0:
                num+=1
                flowerbed[i]=1
        return num>=n
