# 522. Longest Uncommon Subsequence II

class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        strs=sorted(strs)
        strs.sort(key=lambda x:len(x), reverse=True)
        
        if strs[0]!=strs[1]:
            return len(strs[0])
        
        i=1
        self.check_list=[strs[0]]
        while i<len(strs):
            if (i+1)==len(strs):
                if self.check(strs[i]):
                    return len(strs[i])
                else:
                    return -1
            else:
                if strs[i]==strs[i+1]:
                    self.check_list.append(strs[i])
                    while i<len(strs)-1 and strs[i]==strs[i+1]:
                        i+=1
                    continue
                elif self.check(strs[i]):
                    return len(strs[i])
                else:
                    i+=1
        
        return -1
        
    def check(self, s):
        for ref in self.check_list:
            i=0
            for j in ref:
                if j==s[i]:
                    i+=1
                if i==len(s):
                    return False
        return True
