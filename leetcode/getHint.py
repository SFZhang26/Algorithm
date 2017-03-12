# 299. Bulls and Cows

class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bulls=0
        cows=0
        s=[0]*10
        g=[0]*10
        for x, y in zip(secret, guess):
            if x==y:
                bulls+=1
            else:
                s[int(x)]+=1
                g[int(y)]+=1
        for x,y in zip(s,g):
            cows+=min(x,y)
        
        return str(bulls)+"A"+str(cows)+"B"
