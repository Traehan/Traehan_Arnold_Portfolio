inventory = ['health']
health = 10
attack = 2



def battle_w_gob(x,y,z):
    inventory = z
    health = x
    attack = y
    gob_health = 4
    gob_attack = 2
    print('A goblin appeared! Get ready to fight!')
    while health >= 0 and gob_health >= 0:
        f = input('what do you want to do? a/d/h')
        if f == 'a':
            gob_health -= attack
            print('goblin health =',gob_health)
            if gob_health > 0:
                print('goblin attacked!')
                health -= gob_attack
                print('health =',health)
            elif gob_health <= 0:
                break
            continue
        elif f == 'd':
            print('you defended the goblin attack!')
            health -= gob_attack/2
            print('health =',health)
            continue
        elif f == 'h':
            if 'health' in inventory:
                health += 4
                print('health =',health)
                inventory.remove('health')
                print('goblin attacked!')
                health -= gob_attack
                print('health =',health)
            continue
    if gob_health <= 0:    
        print('you won!')
    elif health <= 0:
        print('you lost!')
    x = health
    return(x)
    return(inventory)
    return(attack)


health = battle_w_gob(health,attack,inventory)
print(health)
print(attack)
print('invemtory = ',inventory)
