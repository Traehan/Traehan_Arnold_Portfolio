def common():
    a = input('input a list').split(" ")
    b = input('input a list').split(" ")

    common_list = [x for x in a if x in b]

    print(common_list)
common()
