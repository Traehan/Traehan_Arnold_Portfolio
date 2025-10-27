def carry_on(carry_on_weight):
    if carry_on_weight >= 22:
        print('Check your bag')
    elif carry_on_weight < 22:
        print('you may proceed')
x = int(input('enter the weight of your bag'))
carry_on(x)
