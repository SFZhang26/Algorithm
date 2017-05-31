# 493. Reverse Pairs

class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        re, L = self.sort_and_count(nums)
        return re
    
    def sort_and_count(self, nums):
        if len(nums)<=1:
            return 0, nums
        mid=len(nums)/2
        r_a, A = self.sort_and_count(nums[:mid])
        r_b, B = self.sort_and_count(nums[mid:])
        r=self.count_reverse(A, B)
        L=self.merge(A, B)
        return r_a+r_b+r, L
    
    def count_reverse(self, A, B):
        count = 0
        i, j = 0, 0
        while i<len(A) and j<len(B):
            if A[i]<=B[j]*2:
                i+=1
            else:
                count+=(len(A)-i)
                j+=1
        
        return count

    def merge(self, A, B):
        L=[]
        i, j = 0, 0
        while i<len(A) and j<len(B):
            if A[i]<=B[j]:
                L.append(A[i])
                i+=1
            else:
                L.append(B[j])
                j+=1
        if i<len(A):
            L.extend(A[i:])
        else:
            L.extend(B[j:])
        return L
