# 9. Palindrome Number

class Solution(object):

    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        
        str_x=str(x)
        
        for i in range(len(str_x)/2):
            if str_x[i]!=str_x[len(str_x)-1-i]:
                return False
        
        return True
    
    def isPalindrome2(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        
        x_copy=x
        length=0
        tens=1
        while x_copy>0:
            x_copy/=10
            length=length+1
            tens*=10
        
        tens/=10
        
        for i in range(length/2):
            if (x%10) != (x/tens):
                return False
            x=x-(x%10)*tens
            x/=10
            tens/=100
        
        return True
