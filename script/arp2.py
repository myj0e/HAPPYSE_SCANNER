import re

def gtos(sub,text):
    ret=text[sub[0]:sub[1]]
    return ret,text[sub[1]::]


fp = open("tmp/result.txt","r")
res= open("../../tmp/res.txt","w+")


# while line!= None:
#     line=fp.__next__()
#     print(line)
i=0
for line in fp:
    if ("Internet" in line) or line=="\n":
        continue
    elif "动态" in line:
        res.write(" "+line[0:18]+"\n")
    elif "接口" in line:
        res.write("local_ip:"+line[4:17]+"\n")
    else:
        continue






# while(True):
#     try:
#         subnet=re.search(r'ads: (([01]{0,1}\d{0,1}\d|2[0-4]\d|25[0-5])\.){3}([01]{0,1}\d{0,1}\d|2[0-4]\d|25[0-5])',line)
#     except AttributeError:
        
#     if subnet:
#         subnet=subnet.span()
#         localip,line=gtos(subnet,line)
#         print("local_ip:"+ localip)

res.close()
fp.close()




