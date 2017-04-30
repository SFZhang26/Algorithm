# 566. Reshape the Matrix

class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if len(nums)==0:
            return nums
            
        m=len(nums)
        n=len(nums[0])
        if len(nums)*len(nums[0])!=r*c:
            return nums
        result=[[0]*c for i in range(r)]    
        for k in range(m*n):
            i=int(k/n)
            j=k%n
            result[int(k/c)][k%c]=nums[i][j]
        return result
