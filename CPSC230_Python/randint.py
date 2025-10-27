import random
def high_low(low,high):
    low = int(input('pick a low number'))
    high = int(input('pick a high number'))
    comp_num = random.randint(low, high)
    return comp_num
for i in range(high_low):
    print(i,end='')
