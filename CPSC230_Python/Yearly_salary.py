salary = float(input('How much do you make per hour'))
hours_week = float(input('How many hours do you work per week'))
Yearly_salary = float((salary*hours_week)*52)
print('$',Yearly_salary)

if Yearly_salary >= 100000:
    print('you are rich!')
else:
    print('Keep shooting for the stars!')
