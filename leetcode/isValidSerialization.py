# 331. Verify Preorder Serialization of a Binary Tree

class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        li=list(preorder.split(','))
        num,pound=0,0
        for i in range(len(li)):
            if li[i]=='#':
                pound+=1
                if pound>num and i!=len(li)-1:
                    return False
            else:
                num+=1
        
        return num+1==pound
