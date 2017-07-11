# 640. Solve the Equation

class Solution:
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        leftX, leftV = self.help(equation.split('=')[0])
        rightX, rightV = self.help(equation.split('=')[1])
        
        if leftX==rightX:
            if leftV==rightV:
                return 'Infinite solutions'
            else:
                return 'No solution'
        else:
            return 'x='+str(int((rightV-leftV)/(leftX-rightX)))
    
    def help(self, s):
        val, cof = 0, 0
        sig, temp, i = 1, 0, 0
        flag = True 
        while i < len(s):
            if s[i] == '+':
                val+=(sig*temp)
                sig=1
                temp = 0
            elif s[i]=='-':
                val+=(sig*temp)
                sig=-1
                temp = 0
            elif s[i] =='x':
                if temp == 0 and flag:
                    cof+=sig
                else:
                    cof += (sig*temp)
                sig=1
                temp = 0
            else:
                temp=temp*10+int(s[i])
                if temp ==0:
                    flag=False
                else:
                    flag=True
            i+=1
        if temp!=0:
            val+=(sig*temp)          
        return cof, val
                
