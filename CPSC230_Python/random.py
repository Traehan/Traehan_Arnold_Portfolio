import random
def rando():
    x = int(input('give me one number'))
    y = int(input('give me another'))
    comp_num = random.randint(x,y)
    print(comp_num)
    

rando()
