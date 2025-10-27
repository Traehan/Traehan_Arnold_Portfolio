import csv
csv_file = csv.reader(open('grocery.csv',"r"), delimiter=",")
search = input("What are you looking for?")
for row in csv_file:
    if search in row:
        print('we have it in stock')
        break
    else:
        print('unavailable')
