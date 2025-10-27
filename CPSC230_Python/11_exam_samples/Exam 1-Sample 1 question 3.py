x = int(input('give me number 1'))
y = int(input('give me number 2'))
z = int(input('give me number 3'))

if x == y and x == z and y == z:
    print('All the same!')
elif x != y and x != z and y != z:
    print('All different')
else:
    print('neither')
    
