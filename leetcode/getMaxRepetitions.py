# 466. Count The Repetitions

class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        """
        :type s1: str
        :type n1: int
        :type s2: str
        :type n2: int
        :rtype: int
        """
        repeatCount=[0]*(len(s2)+1)
        nextIndex=[0]*(len(s2)+1)
        j, count = 0, 0
        for k in range(1, n1+1):
            for i in range(len(s1)):
                if s1[i]==s2[j]:
                    j+=1
                    if j==len(s2):
                        j=0
                        count+=1
            
            repeatCount[k]=count
            nextIndex[k]=j
            for start in range(k):
                if nextIndex[start]==j:
                    pre=repeatCount[start]
                    mid=(repeatCount[k]-repeatCount[start])*((n1-start)/(k-start))
                    end=repeatCount[start+(n1-start)%(k-start)]-repeatCount[start];
                    return (pre+mid+end)/n2
        
        return count/n2
