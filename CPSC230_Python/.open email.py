
fin=open('email.txt','w')
fin.write('dear unknown, thank you for shopping with us!')
fin.close()


fin=open('email.txt','r')
fout=open('outemail.txt','w')
name=input('Name of the customer')
for line in fin:
    fout.write(line.replace('unknown',name))
fin.close()
fout.close()
