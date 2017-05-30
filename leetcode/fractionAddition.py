# 592. Fraction Addition and Subtraction

class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        deno = 3628800
        isDeno = False
        curNume = 0
        curDeno = 0
        add = 1
        result = 0
        expression += '+'
        for x in expression:
            if x == '/':
                isDeno = True
            elif x in '+-':
                if curDeno!=0:
                    result += add*curNume*deno/curDeno
                add = 1 if x=='+' else -1
                isDeno= False
                curDeno=0
                curNume=0
            else:
                if isDeno:
                    curDeno = curDeno*10 + int(x)
                else:
                    curNume = curNume*10 + int(x)
        
        x=self.gcd(abs(result), deno)
        re = str(abs(result)/x)+'/'+str(deno/x)
        return '-'+re if result<0 else re
    
    def gcd(self, x, y):
        if y==0:
            return x
        if x<y:
            return self.gcd(y,x)
        else:
            return self.gcd(y, x%y)
        
