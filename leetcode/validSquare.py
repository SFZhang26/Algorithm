# 593. Valid Square

class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        if p1==p2 and p2==p3 and p3==p4:
            return False
        if self.right(p1,p2,p3,p4) or self.right(p1,p3,p2,p4) or self.right(p1,p4,p2,p3):
            return True
        return False
    
    def right(self, p1, p2, p3, p4):
        l1=[p1[0]-p2[0], p1[1]-p2[1]]
        l2=[p3[0]-p4[0], p3[1]-p4[1]]
        if l1[0]*l2[0]+l1[1]*l2[1] !=0:
            return False
        if l1[0]*l1[0]+l1[1]*l1[1] != l2[0]*l2[0]+l2[1]*l2[1]:
            return False
        mid1=[(p1[0]+p2[0])/2.0, (p1[1]+p2[1])/2.0]
        mid2=[(p3[0]+p4[0])/2.0, (p3[1]+p4[1])/2.0]
        if (p1[0]-mid2[0])*(p1[0]-mid2[0])+(p1[1]-mid2[1])*(p1[1]-mid2[1]) != (p2[0]-mid2[0])*(p2[0]-mid2[0])+(p2[1]-mid2[1])*(p2[1]-mid2[1]):
            return False
        if (p3[0]-mid1[0])*(p3[0]-mid1[0])+(p3[1]-mid1[1])*(p3[1]-mid1[1]) != (p4[0]-mid1[0])*(p4[0]-mid1[0])+(p4[1]-mid1[1])*(p4[1]-mid1[1]):
            return False
        return True
