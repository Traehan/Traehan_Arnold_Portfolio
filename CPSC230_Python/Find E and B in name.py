def find(x):
    count = 0
    for i in x:
        if i in ['e','E','b','B']:
            count += 1
    print('there are',count,'E and B in your name')

find(input('What is your first name'))

find(input('What is your last name'))
