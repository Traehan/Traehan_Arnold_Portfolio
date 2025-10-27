z=0
x = int(input("give me a number"))
for i in range(x):
    y = input("please say yes")
    if y.lower() == "yes":
        break
    elif y.lower() != "yes":
        z += 1
print("you did not say yes",z,"amount of times")
