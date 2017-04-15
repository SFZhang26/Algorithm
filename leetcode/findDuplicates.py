# 442. Find All Duplicates in an Array

class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result=[]
        n=len(nums)
        
        for i in range(n):
            sub=nums[i]
            if i==sub-1:
                continue
            nums[i]=-1
            while True:
                if sub==-1:
                    break
                elif nums[sub-1]==sub:
                    result.append(sub)
                    break
                else:
                    temp=nums[sub-1]
                    nums[sub-1]=sub
                    sub=temp
                
        return result
