s = raw_input();
res = ''
for i in s :
    if i.isalpha():
        if i.islower():
            res = res + i.upper()
        else:
            res = res + i.lower()
    else :
        res = res + i
print res
        
        
