answer=input('did you get your first dose of vaccine? yes/no')
if answer=='no':
        print('Get the vaccine')
if answer=='yes':
    second_answer=input('Did you get the second dose? yes/no')
    if second_answer=='no':
            print('get the second dose')
    if second_answer=='yes':
            last_answer=input('did you get the booster? yes/no')
            if last_answer=='yes':
                    print('Complete')
            else:
                    print('get the booster.')
                


