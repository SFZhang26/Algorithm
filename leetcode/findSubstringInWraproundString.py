# 467. Unique Substrings in Wraparound String

class Solution(object):
    def findSubstringInWraproundString(self, p):
        """
        :type p: str
        :rtype: int
        """
        count=[0]*26
        length, result=0, 0
        for i in range(len(p)):
            cur=ord(p[i])-ord('a')
            if i>0 and ord(p[i-1])-ord('a')!=(cur+26-1)%26:
                length=0
            length+=1
            if length>count[cur]:
                result+=length-count[cur]
                count[cur]=length
        return result
