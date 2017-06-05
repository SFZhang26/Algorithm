# 565. Array Nesting

class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        re=[0]*len(nums)
        for i in range(len(nums)):
            if re[i]>0:
                continue
            start=i
            count=0
            while nums[i]!=start and nums[i]!=i and re[i]==0:
                count+=1
                i=nums[i]
            base=re[i]
            i=start
            while nums[i]!=start and nums[i]!=i and re[i]==0:
                if re[i]>0:
                    continue
                re[i]+=(base+count)
                count-=1
                i=nums[i]
            
        return max(max(re),1)
