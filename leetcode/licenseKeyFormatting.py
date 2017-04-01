# 482. License Key Formatting

class Solution(object):
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        s=''.join(S.split('-')).upper()
        start=len(s)%K
        result=s[0:start]
        for i in range(start,len(s),K):
            result+='-'+s[i:i+K]
        return result if start>0 else result[1:]
