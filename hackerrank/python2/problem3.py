s = raw_input();
p = int(raw_input())
li = []
j = 0
for i in range(p+1):
    li.append(s[j:j+p])
    j = j+p
res =[]
for i in li:
    temp = ''
    for j in i :
        if j not in temp :
            temp = temp + j
    res.append(temp)
for i in res :
    if len(i) > 0 :
        print i

        
        
