# 290. Word Pattern

class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words=str.split(' ')
        if len(words)!=len(pattern):
            return False
        
        dict1={}
        dict2={}
        for i in range(len(pattern)):
            if dict1.get(pattern[i],'*')!='*' and dict2.get(words[i],'*')!='*':
                if dict1[pattern[i]]!=words[i] or dict2[words[i]]!=pattern[i]:
                    return False
            elif dict1.get(pattern[i],'*')!='*' or dict2.get(words[i],'*')!='*':
                return False
            else:
                dict1[pattern[i]]=words[i]
                dict2[words[i]]=pattern[i]
        
        return True;
