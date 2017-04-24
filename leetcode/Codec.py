# 535. Encode and Decode TinyURL

class Codec:
    
    def __init__(self):
        self.vec=[]
        
        
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        res= 'http://tinyurl.com/'
        if longUrl in self.vec:
            return res+str(self.vec.index(longUrl))
        else:
            self.vec.append(longUrl)
        return res+str(len(self.vec))
        

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.vec[int(shortUrl.split('/')[-1])-1]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
