# 564. Find the Closest Palindrome

class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        if n=='1':
            return '0'
        if len(n)==1:
            return str(int(n)-1)
        
        rev_1=self.reverse(n)
        dif_1=abs(int(rev_1)-int(n))
        if dif_1==0:
            dif_1=1e19
        
        s=n
        i=(len(s)-1)/2
        while i>=0 and s[i]=='0':
            s=s[:i]+'9'+s[i+1:]
            i-=1
        if i==0 and s[0]=='1':
            s=s[1:]
            mid=(len(s)-1)/2
            s=s[:mid]+'9'+s[mid+1:]
        else:
            s=s[:i]+str(int(s[i])-1)+s[i+1:]
        rev_2=self.reverse(s)
        dif_2=abs(int(rev_2)-int(n))
        
        s=n
        i=(len(s)-1)/2
        while i>=0 and s[i]=='9':
            s=s[:i]+'0'+s[i+1:]
            i-=1
        if i<0:
            s='1'+s
        else:
            s=s[:i]+str(int(s[i])+1)+s[i+1:]
        rev_3=self.reverse(s)
        dif_3=abs(int(rev_3)-int(n))
        
        if dif_2<=dif_1 and dif_2<=dif_3:
            return rev_2
        elif dif_1<=dif_2 and dif_1<=dif_3:
            return rev_1
        else:
            return rev_3
    
    def reverse(self, s):
        half=s[:len(s)/2]
        res=''
        if len(s)%2==1:
            res=s[len(s)/2]
        res=half+res+half[::-1]
        return res
