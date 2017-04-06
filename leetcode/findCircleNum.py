# 547. Friend Circles

class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        n=len(M)
        result=0
        que=[0]
        visited=[False]*n
        while len(que)>0:
            result+=1
            while len(que)>0:
                i=que[0]
                que=que[1:]
                for j in range(n):
                    if visited[j] or M[i][j]==0:
                        continue
                    que.append(j)
                    visited[j]=True
            for i in range(n):
                if not visited[i]:
                    que.append(i)
                    break
        return result
