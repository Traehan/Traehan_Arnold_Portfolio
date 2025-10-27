import random

def func1():
    low = int(input('low number'))
    high = int(input('high number'))
    comp_num = random.randint(low,high)
    return comp_num

def func2():
    print('I am thinking of a number...')
    guess = int(input('what am I thinking?'))
    return guess

def func3():
    x = func1()
    y = func2()
    while x != y:
        
        if y > x:
            print('too high')
        elif y < x:
            print('too low')
        y = func2()
    else:
            print('Correct!')

func3()
