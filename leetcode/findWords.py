# 500. Keyboard Row

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result=[]
        dict={'0':"qwertyuiopQWERTYUIOP",'1':"asdfghjklASDFGHJKL",'2':"ZXCVBNMzxcvbnm"}
        for word in words:
            index=0
            if word[0] in dict['0']:
                index=0
            elif word[0] in dict['1']:
                index=1
            else:
                index=2
            for j in word[1:]:
                if j not in dict[str(index)]:
                    break;
            else:
                result.append(word)
        
        return result
