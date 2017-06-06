# 609. Find Duplicate File in System

class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        m={}
        for item in paths:
            li=item.split()
            path=li[0]
            for file in li[1:]:
                j=file.find('(')
                name=file[:j]
                content=file[j+1:-1]
                if content in m:
                    m[content].append(path+'/'+name)
                else:
                    m[content]=[path+'/'+name]
        
        res=[]
        for key in m:
            if len(m[key])>1:
                res.append(m[key])
        
        return res
