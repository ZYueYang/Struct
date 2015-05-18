#!/usr/bin/python
import urllib2
import urllib
import re
def getHtml(url):
    req = urllib2.urlopen(url)
    html = req.read()
    return html
def getImage(html):
    req = r'src="(.+?\.png)"'
    image = re.compile(req)
    imList = re.findall(image,html)
    x=0
    for imlist in imList:
        urllib.urlretrieve(imlist,"%s.png"%x)
        x+=1   
      

getImage(getHtml("http://www.hao123.com"))
