def func1(a_list,b_list):
    c = sorted(b_list)
    c.reverse()
    c.extend(sorted(a_list))
    c.extend(b_list)
    c.reverse()
    c.remove(3)
    return c
a = [6,5,2,8]
b = [0,-4,7,3]
c = func1(a,b)
print(c)
