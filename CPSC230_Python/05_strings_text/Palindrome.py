def palindrome():
    while True:
        y = str(input('type a palindrome'))
        if y.lower()[::1] == y.lower()[::-1]:
            print('correct!')
            continue
        else:
            print('wrong')
            break


palindrome()
