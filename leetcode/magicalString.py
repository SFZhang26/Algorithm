# 481. Magical String

class Solution(object):
    def magicalString(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==0:
            return 0
        if n<=3:
            return 1
        magic=[1, 2, 2]
        length=3
        i=2
        end=2
        result=1
        while True:
            if end==2:
                for k in range(magic[i]):
                    magic.append(1)
                    result+=1
                    length+=1
                    if length==n:
                        return result
                end=1
            else:
                for k in range(magic[i]):
                    magic.append(2)
                    length+=1
                    if length==n:
                        return result
                end=2
            i+=1
