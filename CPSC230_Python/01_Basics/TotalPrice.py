#Traehan Arnold, TotalPrice.py

initial_price = float(input('what is the initial price of the item?'))

#enter price of item


sales_tax = float(initial_price * 0.072) #Cali sales tax = 7.25%

total_price = float(initial_price + sales_tax)

print('the total price of your item is $',(total_price))
