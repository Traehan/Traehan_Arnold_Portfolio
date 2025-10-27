num1=int(input('First number'))
num2=int(input('First number'))
num3=num1*num2
f=open("numbers.txt","w")
f.write(str(num1))
f.write('*')
f.write(str(num2))
f.write('=')
f.write(str(num3))
f.close()
        
