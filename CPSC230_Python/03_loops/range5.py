x = int(input('How many people are showing up tonight?'))
if x < 10:
    for name in range(x):
        name = input('Who is this attendee?')
        print(name,'has been invited')
else:
    print('too many people')
