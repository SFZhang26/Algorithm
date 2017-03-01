# 166. Fraction to Recurring Decimal

class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator==0:
            return "0"
        
        result=""
        sign=(numerator<0)^(denominator<0)
        dot=False
        n,d=abs(numerator),abs(denominator)
        dict={}
        while True:
            if n<d:
                if not dot:
                    if result=="":
                        result="0."
                    else:
                        result+="."
                    dot=True
                n*=10
            left=n%d;
            if left==0:
                result+=str(n/d)
                return "-"+result if sign else result
            else:
                if dot:
                    if n not in dict:
                        dict[n]=len(result)
                        result+=str(n/d)
                    else:
                        pos=dict[n]
                        result=result[0:pos]+"("+result[pos:]+")"
                        return "-"+result if sign else result
                else:
                    result+=str(n/d)
                n=left
                    
