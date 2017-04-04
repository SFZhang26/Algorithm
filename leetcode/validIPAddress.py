# 468. Validate IP Address

class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if '.' in IP:
            li=IP.split('.')
            if len(li)!=4 or any(len(x)==0 or not x.isdigit() or (len(x)>1 and (x[0]=='0' or int(x)>255)) for x in li):
                return "Neither"
            else:
                return "IPv4"
        elif ':' in IP:
            li=IP.split(':')
            if len(li)!=8 or any(len(x)==0 or len(x)>4 or any(c=='-' or (c.isalpha() and c.upper()>'F') for c in x) for x in li):
                return "Neither"
            else:
                return "IPv6"
        else:
            return "Neither"
