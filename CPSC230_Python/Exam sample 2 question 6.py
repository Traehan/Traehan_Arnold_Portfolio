a = 0
b = 1
limit = 0
while limit < 10:
     if limit == 0:
            print ("1")
            f_int = a + b
            print(f_int)
            a = b
            b = f_int
            limit += 1
            if limit > 7:
                break
