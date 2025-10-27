#2 Complete the code
temperature = int(input("what is the temperature in Fahrenheit"))
if temperature > 90:
    print("is is hot outside")
elif 80 < temperature < 90:
    print('its pretty warm outside')
elif 70 < temperature < 80:
    print('its the perfect temperature')
elif 60 < temperature < 70:
    print('its kind of chilly')
else:
    print('its freezing outside')
