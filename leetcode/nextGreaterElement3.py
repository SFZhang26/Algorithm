# 556. Next Greater Element III

class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        s=str(n)
        index=len(s)-1
        while index>0:
            if s[index-1]<s[index]:
                break
            index-=1
        if index==0:
            return -1
            
        min_index=index
        for i in range(index+1,len(s)):
            if s[i]>s[index-1] and s[i]<s[min_index]:
                min_index=i
    
        new_s=s[:index-1]+s[min_index]+''.join(sorted(s[index-1:min_index]+s[min_index+1:]))
        return -1 if int(new_s)>2147483647 else int(new_s)
