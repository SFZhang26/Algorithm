# 624. Maximum Distance in Arrays

class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        res=0
        max_val=-10001
        max_li=[]
        min_val=10001
        min_li=[]
        for idx, li in enumerate(arrays):
            cur_max=max(li)
            cur_min=min(li)
            if cur_max>max_val:
                max_val=cur_max
                max_li=[idx]
            elif cur_max==max_val:
                max_li.append(idx)
                
            if cur_min<min_val:
                min_val=cur_min
                min_li=[idx]
            elif cur_min==min_val:
                min_li.append(idx)
        if len(max_li)>1 or len(min_li)>1 or min_li!=max_li:
            return max_val-min_val
        index=min_li[0]
        max_val_temp = -10001
        min_val_temp = 10001
        for idx, li in enumerate(arrays):
            if idx==index:
                continue
            max_val_temp=max(max_val_temp, max(li))
            min_val_temp=min(min_val_temp, min(li))
        
        return max(max_val_temp-min_val, max_val-min_val_temp)
