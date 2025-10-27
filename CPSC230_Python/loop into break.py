import random
for i in range(20):
    x=random.randint(1,10)
    print(x)
    if x==9:
        print("The number is 9")
        break
    elif x%2==0:
        print("it is an even number")
        continue
