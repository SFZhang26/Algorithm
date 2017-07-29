# 621. Task Scheduler

class Solution:
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        ret = 0
        c = collections.Counter(tasks)
        que = [c[k] for k in c]
        while True:
            que.sort(reverse=True)
            new_que = []
            i, add = 0, 0
            for j in range(n+1):
                if i>=len(que):
                    break
                if que[i]>1:
                    new_que.append(que[i]-1)
                else:
                    add+=1
                i+=1
            new_que.extend(que[i:])
            if len(new_que) == 0:
                ret+=add
                break
            else:
                ret+=(n+1)
                que=new_que
        return ret
        
