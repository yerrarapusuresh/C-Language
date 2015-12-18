from collections import Counter
s = raw_input()
d = {}
for i in s :
    if i.isalpha():
        try :
            d[i] += 1
        except:
            d[i] = 1
c = Counter(d)
l = list( c.most_common(3))
for i in l :
    j = list(i)
    print j[0],j[1]

        
    



