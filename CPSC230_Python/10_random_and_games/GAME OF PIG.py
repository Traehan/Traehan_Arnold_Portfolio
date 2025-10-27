import random
import time
# Dylam, Roger, Trae
#Just creating variables that will be used later in the game
player1_score = 0
player2_score = 0 
dice_number = 0


#The main while loop that will only keep the game running so long as no one has earned over 100 points
while player1_score < 100 and player2_score < 100:

    #Below is the user's code
    sum = 0
    dice_number = random.randint(1,6)
    print(f'{"The computers score is"} {player2_score}{"."} {"Your score is"} {player1_score}{"."}')
    while input("Would you like to roll? ") != 'yes':
        pass
    while dice_number != 1:
        sum += dice_number
        yes_no = input("You rolled a " + str(dice_number) + ", would you like to continue? " + "Current Score: " + str(player1_score) + " Potential Score: " + str(player1_score + sum) + " ")
        if yes_no.lower() == "r" or yes_no.lower() == "yes":
            dice_number = random.randint(1,6)
        else:
            player1_score += sum
            break
    else:
        print("You rolled a 1. You gain nothing, and your turn is over.\n")
    print("Your current score is",player1_score,"\n")


    if player1_score >= 100:
        break



 #Below is the computer's code
    sum = 0
    dice_number = random.randint(1,6)
    while dice_number != 1:
        time.sleep(3)
        sum += dice_number
        print("The computer rolled a",dice_number,"Potential Score: ", sum+player2_score)
        if sum < 20 and (player2_score + sum <100):
            print("The computer will roll again.")
            dice_number = random.randint(1,6)
        else:
            player2_score += sum
            print("The computer will hold, and its current score is ",player2_score,"\n")
            break
    else:
        sum = 0
        print("The computer rolled a 1. It gains nothing and its turn is over. \n")


if player1_score > player2_score:
    print("You won!!!")
else:
    print("The computer won :(")
