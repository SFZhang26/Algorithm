# 625. Minimum Factorization

class Solution(object):
    def smallestFactorization(self, a):
        """
        :type a: int
        :rtype: int
        """
        self.li = []
        self.flag=False
        self.solve(a, [])
        if len(self.li)==0 or len(self.li[0])>32:
            return 0
        res=min([self.get_num(x) for x in self.li])
        return 0 if res>=2**31 else res
    
    
    def solve(self, a, cur):
        if a<10:
            cur.append(a)
            if len(self.li)>0 and len(cur)>len(self.li[0]):
                self.flag=True
                return
            self.li.append(cur)
            return
        for i in range(2,10)[::-1]:
            if self.flag:
                return
            if a%i==0:
                self.solve(a/i, cur+[i])
                
            
    def get_num(self, vec):
        vec=sorted(vec)
        return sum([10**(len(vec)-1-idx)*num for idx, num in enumerate(vec)])
