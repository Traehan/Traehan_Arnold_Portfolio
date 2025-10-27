name1 = input('Enter first name')
name2 = input('Enter second name')
name3 = input('Enter third name')

list = [name1,name2,name3]
answer = ''
while answer != "no":
    x = input('Do you want to add another name?')
    list.append(x)
    answer = input('Do you want to continue?')
print(list)
