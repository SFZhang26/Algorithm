# 165. Compare Version Numbers

class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        
        v1=list(map(lambda x: int(x), version1.split('.')))
        v2=list(map(lambda x: int(x), version2.split('.')))
        
        for i in range(min(len(v1),len(v2))):
            if v1[i]>v2[i]:
                return 1
            elif v1[i]<v2[i]:
                return -1
        if len(v1)==len(v2) :
            return 0
        elif len(v1)>len(v2):
            if sum(v1[len(v2):])==0:
                return 0
            else:
                return 1
        else:
            if sum(v2[len(v1):])==0:
                return 0
            else:
                return -1
