# 638. Shopping Offers

class Solution:
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        if len(price) == 0:
            return 0
        spec = []
        for sp in special:
            if all(j>=i for i, j in zip(sp[:-1],needs)) and sum([p*n for p, n in zip(price, needs)]) > sp[-1]:
                spec.append(sp)
        self.res = sum([p*n for p, n in zip(price, needs)])
        self.help(price, spec, needs, 0)
        return self.res
    
    def help(self, price, special, needs, cur):
        if all(i==0 for i in needs):
            self.res = min(self.res, cur)
            return
        flag = True
        for sp in special:
            if any(i>j for i, j in zip(sp[:-1], needs)):
                continue
            flag = False
            new_needs = [j - i for i, j in zip(sp[:-1], needs)]
            self.help(price, special, new_needs, cur + sp[-1])
        
        if flag:
            cur += sum([p*n for p, n in zip(price, needs)])
            self.res = min(self.res, cur)
