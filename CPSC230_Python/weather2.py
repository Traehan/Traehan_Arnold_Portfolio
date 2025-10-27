raining = input('is it raining? yes or no.')
if raining.lower() == ('yes'):
    windy = input('is it windy? yes or no')
    if windy.lower() == ('yes'):
        print('it is too windy for an umbrella')
    else:
        print('Enjoy your day!')
else:
    print('beep you!')
