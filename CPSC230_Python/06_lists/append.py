cities = ["Rome", "Paris", "Toronto", "NY"]
newlist=[]
for x in cities:
    if'a' in x:
        newlist.append(x)
print(newlist)

newlist = [x for x in cities if "a" in x]
print(newlist)

grades = [88, 66, 32, 40, 61, 100, 42]

pass_grades = [i for i in grades if i>60]
print(pass_grades)

currency = [[1.00,5.00,10.0], [0.75,3.77,7.53], [0.65,3.25,6.50]]
for row in currency:
    for cell in row:
        print(cell, end=' ')
    print()

grades = [[32,100,80], [99,22,43]]
for row in grades:
    for cell in row:
        print(cell,end='*')
    print()
