my_dict = {1:'one',2:'two',3:'three',4:'four',5:'five'}
my_dict.update({6:'six'})
print(my_dict)
def dict(key):
    x = int(input('type what number you want 1-6'))
    print(my_dict.get(x,'N/A'))

dict(my_dict)

