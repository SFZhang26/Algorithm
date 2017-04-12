# 483. Smallest Good Base

class Solution(object):
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        num=int(n)
        result=0
        for length in range(3,61)[::-1]:
            left=2
            right=int(pow(num, 1.0/float(length-1)))
            
            while left<=right:
                mid=left+int((right-left)/2)
                cur=self.cal(mid,length,num)
                if cur==num:
                    return str(mid)
                elif cur==-1:
                    right=mid-1
                else:
                    left=mid+1
        if result==0:
            return str(num-1)
                
    def cal(self, base, length, n):
        re=0
        for i in range(length):
            re=re*base+1
            if re>n:
                return -1
        return re
