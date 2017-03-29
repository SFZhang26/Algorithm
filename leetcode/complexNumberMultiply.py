# 537. Complex Number Multiplication

class Solution(object):
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        l1=a.split('+')
        a1=int(l1[0])
        b1=int(l1[1][:-1])
        l2=b.split('+')
        a2=int(l2[0])
        b2=int(l2[1][:-1])
        return str(a1*a2-b1*b2)+"+"+str(a1*b2+a2*b1)+"i"
