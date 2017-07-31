# 649. Dota2 Senate

class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """
        count = 0
        senate = [i for i in senate]
        while True:
            r, d = 0, 0
            for i in range(len(senate)):
                if senate[i] == 'R':
                    if count >= 0:
                        r+=1
                    else:
                        senate[i] = 'B'
                    count+=1
                elif senate[i] == 'D':
                    if count <= 0:
                        d+=1
                    else:
                        senate[i] = 'B'
                    count-=1
            
            if r==0:
                return 'Dire'
            elif d ==0:
                return 'Radiant'
                
