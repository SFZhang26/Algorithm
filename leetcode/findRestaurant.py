# 599. Minimum Index Sum of Two Lists

class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        index=len(list1)+len(list2)
        re=[]
        for i in range(len(list1)):
            if list1[i] in list2:
                cur=i+list2.index(list1[i])
                if cur<index:
                    re=[list1[i]]
                    index=cur
                elif cur==index:
                    re.append(list1[i])
        return re
