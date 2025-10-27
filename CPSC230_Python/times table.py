x = int(input('Give me a number between 1 and 12.'))
if 0 <= x <= 12:
    for i in range(13):
        print(i,'*',x,'=',x*i)
else:
    print('not within the range!')
