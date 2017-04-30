# 567. Permutation in String

class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1)>len(s2):
            return False
        count=[0]*26
        cur=[0]*26
        for x,y in zip(s1,s2[:len(s1)]):
            count[ord(x)-ord('a')]+=1
            cur[ord(y)-ord('a')]+=1
        if count==cur:
            return True
        for i in range(len(s1), len(s2)):
            cur[ord(s2[i-len(s1)])-ord('a')]-=1
            cur[ord(s2[i])-ord('a')]+=1
            if cur==count:
                return True
        return False
