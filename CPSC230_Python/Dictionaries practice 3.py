dict = {'a':800,'b':200,'c':500}
min=list(dict.values())[0]
new_key=list(dict.keys())[0]

for key,value in dict.items():
    if value<min:
        min=value
        new_key=key
print(new_key)
