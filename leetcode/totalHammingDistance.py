# 477. Total Hamming Distance

class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=0
        count=[0]*32
        for num in nums:
            s=bin(num)
            for i in range(len(s)-2):
                if s[len(s)-1-i]=='1':
                    count[i]+=1
        for i in count:
            result+=i*(len(nums)-i)
        return result
