# 71. Simplify Path

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        li=path.split('/')
        result_list=[]
        result=""
        for i in li:
            if i=="..":
                if result_list:
                    result_list.pop()
            elif i!="." and i!="":
                result_list.append(i)
        
        if result_list:
            result=reduce(lambda x,y:x+"/"+y,result_list)
        return "/"+result
