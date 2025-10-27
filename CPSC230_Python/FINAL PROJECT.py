#My goal is to make an rpg like game where you enter 10 rooms, collect items,
#fight monsters and kill the boss at the very end.
#using lists, if/else statements, and functions to create a game where you choose your own path to the goal

#character(you)
#this is the foundation of the character you 
inventory = ['health potion']
health = 10
attack = 2

def battle_w_gob(x,y,z): #basic monster you first encounter
    inventory = z
    health = x
    attack = y
    gob_health = 4
    gob_attack = 2
    print('A goblin appeared! Get ready to fight!')
    print('Goblin health =',gob_health)
    print('Goblin attack =',gob_attack)
    while health > 0 and gob_health > 0:
        f = input('what do you want to do? a/d/h')
        if f.lower() == 'a':
            gob_health -= attack
            print('goblin health =',gob_health)
            if gob_health > 0:
                print('goblin attacked!')
                health -= gob_attack
                print('health =',health)
            elif gob_health <= 0:
                break
            continue
        elif f.lower() == 'd':
            print('you defended the goblin attack!')
            print('health =',health)
            continue
        elif f.lower() == 'h':
            if 'health potion' in inventory:
                health += 7
                print('health =',health)
                inventory.remove('health potion')
                print('goblin attacked!')
                health -= gob_attack
                print('health =',health)
            continue
    if gob_health <= 0:    
        print('you won!')
    elif health <= 0:
        print('you lost!')
        beginning()#if you lose you go back to the function beginning()
    x = health
    return(x,attack,inventory)
   
def battle_w_ogre(x,y,z): #similar kind of coding, however a little different due to the stats and it's reaction to you healing
    inventory = z
    health = x
    attack = y
    ogre_health = 12
    ogre_attack = 3
    print('An ogre appeared! Get ready to fight!')
    print('Ogre health =', ogre_health)
    print('Ogre attack =',ogre_attack)
    while health > 0 and ogre_health > 0:
        f = input('what do you want to do? a/d/h')
        if f.lower() == 'a':
            ogre_health -= attack
            print('ogre health =',ogre_health)
            if ogre_health > 0:
                print('the ogre attacked!')
                health -= ogre_attack
                print('health =',health)
            elif ogre_health <= 0:
                break
            continue
        elif f.lower() == 'd':
            print('you defended the ogre attack!')
            print('health =',health)
            continue
        elif f.lower() == 'h':
            if 'health potion' in inventory:
                health += 7
                print('health =',health)
                inventory.remove('health potion')
                print('the ogre was confused at what you were doing and did not attack!')
                print('health =',health)
            continue
    if ogre_health <= 0:    
        print('you won!')
    elif health <= 0:
        print('you lost!')
        beginning()
    x = health
    return(x,attack,inventory)

def battle_w_ghost(x,y,z): #different enemy, coding is different due to it recieving double damage when you defend it's attack
    inventory = z
    health = x
    attack = y
    ghost_health = 9
    ghost_attack = 2
    print('A ghost appeared! Get ready to fight!')
    print('Ghost health =',ghost_health)
    print('Ghost attack =',ghost_attack)
    while health > 0 and ghost_health > 0:
        f = input('what do you want to do? a/d/h')
        if f.lower() == 'a':
            ghost_health -= attack
            print('ghost health =',ghost_health)
            if ghost_health > 0:
                print('ghost attacked!')
                health -= ghost_attack
                print('health =',health)
            elif ghost_health <= 0:
                break
            continue
        elif f.lower() == 'd':
            print('you defended the ghost attack!')
            print('health =',health)
            print('the ghost is stunned! your attack will do double!')
            j = input('what do you want to do? a/d/h')
            if j.lower() == 'a':
                ghost_health -= attack*2
                print('ghost health =',ghost_health)
                if ghost_health > 0:
                    print('ghost attacked!')
                    health -= ghost_attack
                    print('health =',health)
            elif f.lower() == 'h':
                if 'health potion' in inventory:
                        health += 5
                        print('health =',health)
                        inventory.remove('health potion')
                        print('ghost attacked!')
                        health -= ghost_attack
                        print('health =',health)
                elif f.lower() == 'd':
                    print('you defended the ghost attack!')
                    print('health =',health)
            continue
        elif f.lower() == 'h':
            if 'health potion' in inventory:
                health += 7
                print('health =',health)
                inventory.remove('health potion')
                print('ghost attacked!')
                health -= ghost_attack
                print('health =',health)
            continue
    if ghost_health <= 0:    
        print('you won!')
    elif health <= 0:
        print('you lost!')
        beginning()
    x = health
    return(x,attack,inventory)

def battle_w_king(x,y,z): #final boss monster, much tougher compared to the ones original fought against you
    inventory = z
    health = x
    attack = y
    king_health = 16
    king_attack = 4
    print('The King has appeared! Get ready to fight!')
    print('King health =',king_health)
    print('King attack =',king_attack)
    while health > 0 and king_health > 0:
        f = input('what do you want to do? a/d/h')
        if f.lower() == 'a':
            king_health -= attack
            print('King health =',king_health)
            if king_health > 0:
                print('The King attacked!')
                health -= king_attack
                print('health =',health)
            elif king_health <= 0:
                break
            continue
        elif f.lower() == 'd':
            print('you barely defended The Kings attack!')
            health -= king_attack - 2
            print('health =',health)
            continue
        elif f.lower() == 'h':
            if 'health potion' in inventory:
                health += 7
                print('health =',health)
                inventory.remove('health potion')
                print('the King uses this time to get stronger!')
                king_attack += 1
                print('King attack =',king_attack)
                print('health =',health)
            continue
    if king_health <= 0:    
        print('you won!')
    elif health <= 0:
        print('you lost!')
        beginning(health,attack,inventory)
    x = health
    return(x,attack,inventory)

        
def beginning(health,attack,inventory):
    print('Hi! Welcome to the game, hope you make it all the way!\nIn this game, your goal is to make smart decisions and save the princess!')
    y = input('would you like to begin? y/n')
    if y.lower() =='y':
        print('Good luck!')
        print('health =',health)
        print('attack stat =',attack)
        print('inventory =',inventory)
        print('instructions:\na= attack\nd= defend (can be good to use against certain monsters)\nh= to heal 7 health(only if you have health potion(s) in your inventory)')
        room1(health,attack,inventory)
    else:
        print('goodbye!')

def room1(health,attack,inventory):
    print('you enter a room with two chests')
    x = input('do you choose right or left? R/L')
    if x.lower() == 'r':
        inventory.append('health potion')
        print('you gained a health potion!')
    elif x.lower() == 'l':
        print('the chest has a better sword!')
        attack += 1
        print('attack =',attack)
    e = input('press anything to continue')
    if e != '':
        print('entering room 2...')
        room2(health,attack,inventory)
        
def room2(health,attack,inventory):
    print('you walk into a mini arena and get ambushed by a goblin!')
    health,attack,inventory = battle_w_gob(health,attack,inventory)
    print('health =',health)
    print('inventory = ',inventory)
    e = input('press anything to continue')
    if e != '':
        print('entering room 3...')
        room3(health,attack,inventory)
        
def room3(health,attack,inventory):
    print('you enter a chamber with a mysterious man behind the table')
    print('he offers you +2 attack in exchange for -2 of your health')
    f = input('do you accept this offer? y/n')
    if f.lower() == 'y':
        attack += 2
        health -= 2
    elif f.lower() == 'n':
        print('you deny the deal')
    print('health = ',health)
    print('attack =',attack)
    e = input('press anything to continue')
    if e != '':
        print('you continue on...')
        room4(health,attack,inventory)
    
    
def room4(health,attack,inventory):
    print('you walk into a mini arena and get ambushed by a goblin!')
    health,attack,inventory = battle_w_gob(health,attack,inventory)
    print('health =',health)
    print('inventory = ',inventory)
    e = input('press anything to continue')
    if e != '':
        print('entering room 5...')
        room5(health,attack,inventory)

def room5(health,attack,inventory):
    print('you shove aside a boulder and enter a dimly lit cave')
    print('you burn a torch and in front of you stands a giant ogre!')
    health,attack,inventory = battle_w_ogre(health,attack,inventory)
    room6(health,attack,inventory)

def room6(health,attack,inventoy):
    print('emerging from the cave, you enter a nice sanctuary with a')
    print('beautiful waterfall and lake')
    print('you see something in the water swim towards you fast')
    e = input('Do you run away? y/n')
    if e.lower() == 'n':
        print('a beautiful mermaid emerges from the water and heals you!')
        health += 5
        print('health =',health)
    elif e.lower() == 'y':
        print('you ran away into the safety of the forest!')
    l = input('press anything to continue')
    if l != '':
        print('entering the forest...')
        room7(health,attack,inventory)

def room7(health,attack,inventory):
    print('intent on saving the princess, you keep trecking')
    print('you manage to reach the castle and enter the gates')
    print('However you get pushed back and encounter another ogre!')
    health,attack,inventory=battle_w_ogre(health,attack,inventory)
    print('you are now able to enter the castle')
    room8(health,attack,inventory)

def room8(health,attack,inventory):
    print('inside the castle, you find a secret cabinet leading to a hidden room...')
    e = input('do you take the room? y/n')
    if e.lower() == 'y':
        print('you encounter an armored ghost!')
        health,attack,inventory=battle_w_ghost(health,attack,inventory)
        print('you searched around and found a health potion!')
        inventory.append('health potion')
        print(inventory)
    elif e.lower() == 'n':
        print('you move past the room')
    l = input('press anything to continue')
    if l != '':
        print('you go up higher into the castle')
        room9(health,attack,inventory)

def room9(health,attack,inventory):
    print('you get closer to the throne room where the princess is being held captive')
    print('all of a sudden two armored ghosts emerge to defend the door!')
    health,attack,inventory=battle_w_ghost(health,attack,inventory)
    print('the other ghost jumps in!')
    health,attack,inventory=battle_w_ghost(health,attack,inventory)
    print('after defeating the ghosts, you gather their armor and reinforce yourself')
    health += 6
    print('health =', health)
    l = input('press anything to continue')
    if l != '':
        print('entering the throne room...')
        room10(health,attack,inventory)

def room10(health,attack,inventory):
    print('in the throne room, you spot the princess!\nYou run to save her, however the Evil King stands in your way!')
    battle_w_king(health,attack,inventory)
    print('Congrats! you managed to save the princess and won the game!')
    e = input('would you like to play again? y/n')
    if e.lower() == 'y':
        health = 10
        attack = 2
        inventory = ['health potion']
        beginning(health,attack,inventory)
    else:
            print('Goodbye!')
beginning(health,attack,inventory) #initiates every sequence of events in order

