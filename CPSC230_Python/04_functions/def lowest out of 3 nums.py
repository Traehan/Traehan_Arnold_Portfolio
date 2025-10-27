def lowest_num(one, two, three):
    order = [one, two, three]
    if one < two:
        if one < three:
            return one
    if two < one:
        if two < three:
            return two
    if three < one:
        if three < two:
            return three
x = int(input('Give me your first number'))
y = int(input('Give me your second number'))
z = int(input('Give me your third number'))
lowest_num(x,y,z)
