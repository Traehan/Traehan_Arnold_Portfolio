def Find_A(name):
    count = 0
    for i in name:
        if i.lower() == 'a':
            count += 1
    print('there are', count, 'As in your name')

name = input('What is your name?')
Find_A(name)

