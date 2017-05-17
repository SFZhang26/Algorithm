# 582. Kill Process

class Solution(object):
    def killProcess(self, pid, ppid, kill):
        """
        :type pid: List[int]
        :type ppid: List[int]
        :type kill: int
        :rtype: List[int]
        """
        children = collections.defaultdict(list)
        for i in range(len(pid)):
            children[ppid[i]].append(pid[i])
        res=[]
        stk=[kill]
        while stk:
            cur=stk.pop()
            res.append(cur)
            stk.extend(children[cur])
        
        return res
