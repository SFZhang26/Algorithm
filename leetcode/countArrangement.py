# 526. Beautiful Arrangement

class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N==0:
            return 0
        used=[False]*(N+1)
        self.result=0
        self.recur(1,used)
        return self.result
    
    def recur(self, index, used):
        if index>=len(used):
            self.result+=1
            return
        for i in range(1,len(used)):
            if not used[i] and (i%index==0 or index%i==0):
                used[i]=True
                self.recur(index+1, used)
                used[i]=False
